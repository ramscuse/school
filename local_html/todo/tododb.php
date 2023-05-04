<?php
use \Model\TodoDBModel;

class Controller_TodoDB extends Controller {
    public function action_index() {
        $data = array(
            'todos' => TodoDBModel::read_todos(),
            'todo_count' => TodoDBModel::todo_count()
        );
        return Response::forge(View::forge('tododbviews/todomaincontent', $data));
    }

    public function post_index() {
        if (isset($_POST['add']) && isset($_POST['todo_text'])) {
            TodoDBModel::add_todo($_POST['todo_text']);
        }
        if (isset($_POST['delete']) && isset($_POST['todocheck'])) {
            $checked_todos = array();
            foreach ( $_POST['todocheck'] as $id ) {
                $checked_todos[] = $id;
            }
            TodoDBModel::delete_todos($checked_todos);
        }
        $data = array(
            'todos' => TodoDBModel::read_todos(),
            'todo_count' => TodoDBModel::todo_count()
        );
        return Response::forge(View::forge('tododbviews/todomaincontent', $data));
    }
}
?>
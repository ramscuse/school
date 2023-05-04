<p>Todo App</p>
<form method='POST'>
<?php
    foreach ($todos as $todo) {
        $text = $todo['text'];
        $id = $todo['id'];
        echo "<input type='checkbox' value='$id' name='todocheck[]'>";
        echo "&nbsp;";
        echo "<label>" . $text . "</label><br>";
    }
?>
    <br>
    <input type='submit' value='Cross off todos' name='delete'>
</form>
<form method="POST">
    <span>Todo: </span><input type="text" name="todo_text"></input>
    <input type="submit" value="Add new todo" name='add'></input>
</form>

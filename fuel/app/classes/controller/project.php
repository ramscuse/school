<?php

class Controller_Project extends Controller_Template
{
	/**
	 * The basic welcome message
	 *
	 * @access  public
	 * @return  Response
	 */
	public $template = 'templateProject';

	public function action_index()
	{
		$this->template->title = 'Home';
        $this->template->home = 'class=open';
        $this->template->about = '';
		$this->template->color = '';
		$this->template->css = 'home.css';

        $this->template->content=View::forge('project/index');
	}

	public function action_about()
	{
		$this->template->title = 'About';
        $this->template->home = '';
        $this->template->about = 'class=open';
		$this->template->color = '';
		$this->template->css = 'home.css';

        $this->template->content=View::forge('project/about');
	}

	public function action_color()
	{
		$this->template->title = 'Color Generator';
        $this->template->home = '';
        $this->template->about = '';
		$this->template->color = 'class=open';
		$this->template->css = 'home.css';

        $this->template->content=View::forge('project/color');
	}
}

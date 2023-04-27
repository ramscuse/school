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
	public $defaultSize = 'size=10';
	public $defaultColor = 'colors=4';

	public function action_index()
	{
		$this->template->title = 'Home';
		$this->template->home = 'class=open';
		$this->template->about = '';
		$this->template->color = '';
		$this->template->css = 'home.css';
		$this->template->size = $this->defaultSize;
		$this->template->coloramount = $this->defaultColor;


		$this->template->content=View::forge('project/index');
	}

	public function action_404()
	{
		$this->template->title = 'OOPSIE WOOPSIE!!';
		$this->template->home = '';
		$this->template->about = '';
		$this->template->color = '';
		$this->template->css = 'home.css';
		$this->template->size = $this->defaultSize;
		$this->template->coloramount = $this->defaultColor;

		$this->template->content=View::forge('project/404');
	}

	public function action_about()
	{
		$this->template->title = 'About';
		$this->template->home = '';
		$this->template->about = 'class=open';
		$this->template->color = '';
		$this->template->css = 'home.css';
		$this->template->size = $this->defaultSize;
		$this->template->coloramount = $this->defaultColor;

		$this->template->content=View::forge('project/about');
	}

	public function action_color()
	{
		$data = array();
		$this->template->title = 'Color Generator';
		$this->template->home = '';
		$this->template->about = '';
		$this->template->color = 'class=open';
		$this->template->css = 'home.css';
		$this->template->size = $this->defaultSize;
		$this->template->coloramount = $this->defaultColor;

		if(isset($_GET['size']) && isset($_GET['colors'])) {
			$size = $_GET['size'];
			$coloramount = $_GET['colors'];
			$colorlist= array(
				"red" => "#FF0000",
				"blue" => "#0000FF",
				"green" => "#00FF00",
				"yellow" => "#FFFF00",
				"teal" => "#00FFFF",
				"purple" => "#5F04B4",
				"pink" => "#FA58F4",
				"orange" => "#FF8000",
				"white" => "#FFFFFF",
				"black" => "#000000"
			);

			if ($size > 0 && $coloramount > 0 && $size <= 26 && $coloramount <= 10) {
				$data['size'] = $size;
				$data['coloramount'] = $coloramount;
				$data['colors'] = $colorlist;
				$this->template->content=View::forge('project/color',$data);
			} else {
				$data['error'] = "Error: Incorret Values for either size or color";
				$this->template->content=View::forge('project/color',$data);
			}
		} else {
			$data['error'] = "Error: Must Provide paramenters";
			$this->template->content=View::forge('project/color',$data);
		}
	}
}

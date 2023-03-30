<?php

class Controller_EastWest extends Controller_Template
{
	/**
	 * The basic welcome message
	 *
	 * @access  public
	 * @return  Response
	 */
	public $directionWest = "?direction=west";
	public $directionEast = "?direction=east";

	public function action_index()
	{
		$this->template->title = 'Home';
		$this->template->home = 'class=open';
		$this->template->one = '';
		$this->template->two = '';
		$this->template->content=View::forge('eastwest/index');

		if(isset($_GET['direction'])) {
			$dir = $_GET['direction'];
			if ($dir == 'east')  {
				$this->template->css = 'east.css';
				$this->template->direction = $this->directionEast;
				$this->template->direction2 = $this->directionWest;
				$this->template->place = 'West';
			} elseif ($dir == 'west') {
				$this->template->css = 'west.css';
				$this->template->direction = $this->directionWest;
				$this->template->direction2 = $this->directionEast;
				$this->template->place = 'East';
			}
		} else {
			$this->template->css = 'east.css';
			$this->template->direction = $this->directionEast;
			$this->template->direction2 = $this->directionWest;
			$this->template->place = 'West';
		}
	}

	public function action_one()
	{
		$this->template->title = 'One';
		$this->template->home = '';
		$this->template->one = 'class=open';
		$this->template->two = '';

		$this->template->content=View::forge('eastwest/one');

		if(isset($_GET['direction'])) {
			$dir = $_GET['direction'];
			if ($dir == 'east')  {
				$this->template->css = 'east.css';
				$this->template->direction = $this->directionEast;
				$this->template->direction2 = $this->directionWest;
				$this->template->place = 'West';
			} elseif ($dir == 'west') {
				$this->template->css = 'west.css';
				$this->template->direction = $this->directionWest;
				$this->template->direction2 = $this->directionEast;
				$this->template->place = 'East';
			}
		} else {
			$this->template->css = 'east.css';
			$this->template->direction = $this->directionEast;
			$this->template->direction2 = $this->directionWest;
			$this->template->place = 'West';
		}
	}

	public function action_two()
	{
		$this->template->title = 'Two';
		$this->template->home = '';
		$this->template->one = '';
		$this->template->two = 'class=open';

		$this->template->content=View::forge('eastwest/two');

		if(isset($_GET['direction'])) {
			$dir = $_GET['direction'];
			if ($dir == 'east')  {
				$this->template->css = 'east.css';
				$this->template->direction = $this->directionEast;
				$this->template->direction2 = $this->directionWest;
				$this->template->place = 'West';
			} elseif ($dir == 'west') {
				$this->template->css = 'west.css';
				$this->template->direction = $this->directionWest;
				$this->template->direction2 = $this->directionEast;
				$this->template->place = 'East';
			}
		} else {
			$this->template->css = 'east.css';
			$this->template->direction = $this->directionEast;
			$this->template->direction2 = $this->directionWest;
			$this->template->place = 'West';
		}
	}
}

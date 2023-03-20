<head>
    <title>
        <?php echo $title ?>
    </title>
    <?php echo Asset::css($css) ?>
</head>

<nav>
    <ul class="nav-ul">
        <?php echo '<li><a href="https://www.cs.colostate.edu:4444/~ramscuse/cs312/fuelviews/index.php/eastwest/index'.$direction.'" '.$home.'>Home</a></li>' ?>
        <?php echo '<li><a href="https://www.cs.colostate.edu:4444/~ramscuse/cs312/fuelviews/index.php/eastwest/one'.$direction.'" '.$one.'>One</a></li>' ?>
        <?php echo '<li><a href="https://www.cs.colostate.edu:4444/~ramscuse/cs312/fuelviews/index.php/eastwest/two'.$direction.'" '.$two.'>Two</a></li>' ?>

        <?php echo '<li class="switch"><a href="https://www.cs.colostate.edu:4444/~ramscuse/cs312/fuelviews/index.php/eastwest/index'.$direction2.'">'.$place.'</a></li>' ?>
    </ul>
</nav>

<body>
    <?php echo $content;?>
</body>


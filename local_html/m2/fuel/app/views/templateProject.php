<head>
    <title>
        <?php echo $title ?>
    </title>
    <?php echo Asset::css($css) ?>
</head>

<nav>
    <ul class="nav-ul">
        <?php echo '<li><a href="https://www.cs.colostate.edu:4444/~ramscuse/m2/" '.$home.'>Home</a></li>' ?>
        <?php echo '<li><a href="https://www.cs.colostate.edu:4444/~ramscuse/m2/index/project/about" '.$about.'>About</a></li>' ?>
        <?php echo '<li><a href="https://www.cs.colostate.edu:4444/~ramscuse/m2/index/project/color?'.$size.'&'.$coloramount.'" '.$color.'>Color Generator</a></li>' ?>
    </ul>
</nav>

<body>
    <?php echo $content;?>
</body>

<footer>
  LOCAL FUEL
</footer>

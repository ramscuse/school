<!DOCTYPE html>
<html>
<head>
    <title>jQuery Practice</title>
    <!-- Linking to web resource -->
    <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
    <!-- Or if you download and package with your site -->
    <!-- <script src="jquery-3.4.1.min.js"></script> -->
    <link rel="stylesheet" href="jquery_practice.css" type="text/css">
    <script type="text/javascript" src="jquery_practice.js"></script>
</head>
<body>
    <!-- Center this using query -->
    <h3 id="part1">You can download the jQuery source at <a href="https://jquery.com/download/">jQuery</a></h3>

    <div id="part2">
        <p>
            Here is some text and other useless information.
            Lorem Ipsum is simply dummy text of the printing and typesetting industry. 
            Lorem Ipsum has been the industry's standard dummy text ever since the 1500s, 
            when an unknown printer took a galley of type and scrambled it to make a type specimen book. 
            It has survived not only five centuries, but also the leap into electronic typesetting, 
            remaining essentially unchanged. 
            It was popularised in the 1960s with the release of Letraset sheets containing Lorem Ipsum passages, 
            and more recently with desktop publishing software like Aldus PageMaker including versions of Lorem Ipsum
        </p>
        <div id="image">
            <!-- Image is embedded as base64 encoded code so you don't have to download it -->
        </div>
    </div>

    <button id="button1">Center the Header</button>
    <button id="button2">Hide the image</button>
    <button id="button3">Reveal the Image</button>
    <button id="button4">Slide Part 2 Div Open</button>
    <button id="button5">Slide Part 2 Div Closed</button>
    <button id="button6">Toggle Image</button>
</body>
</html>
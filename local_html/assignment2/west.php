<!DOCTYPE html>
<html>
    <head>
        <link rel="stylesheet" type="text/css" href="../recipe.css">
        <style>
            body {
                background-color: #29524A;
            }
            .westContent{
                display: block;
                padding: 11%;
                min-width: 600px;
                width: 90%;
            }
            footer {
                background-color: #102542;
            }
            .nav-ul {
                background-color:#94A187;
                position: fixed;
                padding: 0;
                margin-top: 0;
                width: 10%;
                height: 100%;
            }
            .nav-ul .git {
                float: left;
            }
        </style>
    </head>
    
    <nav>
        <ul class="nav-ul">
            <li><a href="../index.php">Home</a></li>
            <li><a href="../about.html">About Me</a></li>
            <li><a href="../assignment1/ramscuse.php">Assignment 1</a></li>
            <li class="dropdown" class="open">
                <div class="dropbtn">Assignment 2</div>
                <div class="dropdown-content">
                    <a href="east.php">East</a>
                    <a href="west.php">West</a>
                </div>
            </li>
            <li class="git"><a href="https://github.com/ramscuse">gitHub</a></li>
        </ul>
    </nav>

    <header>
        <h1>Jameson Walter</h1>
    </header>
    
    <body>
        <div class="westContent">
            <p>I had ChatGPT write 2 paragraphs on HTML and PHP.</p>
            <p>
                HTML (Hypertext Markup Language) is a standard markup language used to create web pages. 
                It is the fundamental building block of the World Wide Web and is responsible for the structure and content of web pages. 
                HTML is a relatively simple language, and its syntax consists of tags, which are used to describe the different 
                elements of a web page, such as headings, paragraphs, images, and links. HTML files are text documents that can be 
                created using any text editor and viewed in a web browser. HTML is an essential skill 
                for anyone interested in creating web pages or working with web content.
            </p>
            <p>
                PHP (Hypertext Preprocessor) is a server-side scripting language used for web development. 
                It is a powerful tool for creating dynamic web pages, and it is often used in conjunction with HTML. 
                PHP code is executed on the server, and its output is sent to the client's web browser as HTML. This makes 
                it possible to create dynamic content, such as user registration forms, online shopping 
                carts, and interactive web applications. PHP is an open-source language, which means it is free to use and can be modified 
                to suit specific needs. PHP is a popular language for web development, and many of the world's most 
                popular websites, including Facebook and Wikipedia, use PHP to power their sites.
            </p>
        </div>
    </body>

    <footer>
        <h3>LOCAL</h3>
    </footer>
</html>
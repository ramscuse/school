<!DOCTYPE html>
<html>
    <head>
        <style>
            .member {
                display: flex;
                gap: 25px;
                margin: 25px;
            }
            .member > div {
              text-align: center;
            }
            .member img {
                display: block;
                height: 300px;
                width: 300px;
                margin-left: auto;
                margin-right: auto;
            }
            .member h2 {
                font-weight: bold;
                font-size: 18px;
            }
            .member:not(:last-child) {
                border-bottom: 2px dashed rgba(0,0,0,.5);
            }
        </style>
    </head>

    <header>
        <h1>About Us</h1>
    </header>

    <body>
        <main>
                <?php
                define('MEMBER', ['img','imgalt','desc']);
                $members = [
                    "Jameson W" => array_combine(MEMBER, [
                        'jameson.jpg',

                        "Photo of Jameson W",

                        "I am a student at CSU studying computer science with a concentration in software engineering. I play video games and basketball in my free time.",
                    ]),
                    "Benjamin Perry" => array_combine(MEMBER, [
                        'bengine.jpg',

                        "Photo of Benjamin P standing next to a hoisted car engine",

                        "I am a CSU computer science student and UNIX enthusiast.  I'm a general taker-aparter of things and a massive nerd.  I spend most of my time either sleeping, disassembling vacuum cleaners, or obsessively tweaking my dotfiles.",
                    ]),
                    "Nael Eyob" => array_combine(MEMBER, [
                        'nael.jpg',

                        "Photo of Nael Eyob",

                        "I am a student at CSU majoring in computer science. I Spend most of my free time playing sports, video games, or learning about pen testing.",
                    ]),
                    "Andrew Borchert" => array_combine(MEMBER, [
                        'andrew.jpeg',

                        "Photo of Andrew",

                        "I am a third year computer science major with a concentration in networks and security. I enjoy sports, video games, and playing guitar in my free time.",
                    ]),
                ];

                foreach ($members as $name => $about) {
                    echo "<div class=member>";
                    echo "    <div>";
                    echo "        <img src='".Asset::get_file($about['img'], 'img')."' alt='".$about['imgalt']."'>";
                    echo "        <h2>".$name."</h2>";
                    echo "    </div>";
                    echo "    <p>".$about['desc']."</p>";
                    echo "</div>";
                }
                ?>
        </main>
    </body>
</html>

<!DOCTYPE html>
<html>
    <head>
        <style>
            table {
                color: black;
                width: 100%;
            }
            tr, td {
                border: 1px solid;
            }
            .table-color .left{
                width: 20%;
            }
            .table-color .right{
                width: 70%;
            }
            .table-color .radio{
                border: none;
            }
            .table-paint {
                border: 1px solid;
                border-collapse: collapse;
            }
            .table-paint td{
                width : 200px;
                height : 40px;
            }
            .dropdown .dropbtn {
                padding: 20px 25px;
                color: black;
            }
            .dropdown-content {
                display: none;
                position: absolute;
                background-color: white;
                box-shadow: 0px 8px 16px 0px rgba(0,0,0,0.2);
                z-index: 1;
            }
            .dropdown-content p {
                border: 1px solid;
                padding: 5px 50px;
                margin: 0;
                text-decoration: none;
                display: block;
                text-align: left;
            }
            .dropdown .dropbtn:hover {
                color: #2C363F;
                background-color: #D6DBD2;
            }
            .dropdown:hover .dropdown-content {
                display: block;
            }
        </style>
        <script type="text/javascript" src="https://ajax.googleapis.com/ajax/libs/jquery/3.6.4/jquery.min.js"></script>
        <script>
            function update() {
                var size = document.getElementById("size").value;
                var colors = document.getElementById("color").value;
                var url = new URL(window.location.href);
                var search_params = url.searchParams;

                search_params.set('size',size);
                search_params.set('colors',colors);

                url.search = search_params.toString();

                var new_url = new URL(url.toString());

                location.href = new_url;
            }
            function radioValue() {
                var rad = document.getElementsByName('color-select');
                for (i = 0; i < rad.length; i++) {
                    if (rad[i].checked) {
                        return rad[i].value;
                    }
                }
            }
            $("document").ready(() => {
                $('.table-color tr .dropdown').each(function() {
                    $(this).find('div p').each(function() {
                        $(this).click(() => {
                            color = $(this).attr('href');
                            colorname = $(this).attr('class')
                            id = $(this).attr('id');
                            $('.table-color .right').each(function() {
                                if (id === $(this).attr('id')) {
                                    $(this).css('background-color', color);
                                    $(this).attr('color',colorname)
                                }
                            })
                            $('.table-color .radio input').each(function() {
                                if (id === $(this).attr('id')) {
                                    $(this).attr('value',color)
                                }
                            })
                        })
                    })
                })
                $('.table-paint tr').each(function() {
                    $(this).find('.clickable').each(function() {
                        $(this).click(() => {
                            val = radioValue();
                            if (val != 'on') {
                                $(this).css('background-color',val);
                            }
                        })
                    })
                })
                // Not Implemented Yet
                function colorClick(color) {
                    $('.'+color).each(() => {
                        $(this).attr('selected','true');
                    })
                }
            });
        </script>
    </head>

    <header>
        <h1>Color Coordinate Generator</h1>
    </header>

    <body>
        <main>
            <?php
                if (isset($size) && isset($coloramount)) {
                    echo '<div style=margin-bottom:25px;>';
                    echo '<label for="size">Size: </label>';
                    echo '<input type="text" id="size" name="size" value="'.$size.'">';
                    echo '<label for="color">Color Amount: </label>';
                    echo '<input type="text" id="color" name="color" value="'.$coloramount.'">';
                    echo '<button onclick="update()">Update</button>';
                    echo '</div>';

                    echo '<table class="table-color">';
                    echo '<form>';
                    for ($i = 0; $i < $coloramount; $i++) {
                        echo '<tr>';
                        echo '<td id='.$i.' class="dropdown">';
                        echo '<div class=dropbtn>Color</div>';
                        echo '<div class="dropdown-content">';
                        foreach ($colors as $name => $val) {
                            echo '<p class="'.$name.'" id="'.$i.'" href="'.$val.'">'.$name.'</p>';
                        }
                        echo '</div>';
                        echo '</td>';
                        echo '<td id="'.$i.'"class="right">';
                        echo '</td>';
                        echo '<td class="radio">';
                        if ($i == 0) {
                            echo '<input type="radio" id="'.$i.'" name="color-select" checked="checked"></input>';
                        } else {
                            echo '<input type="radio" id="'.$i.'" name="color-select"></input>';
                        }
                        echo '</td>';
                        echo '</tr>';
                    }
                    echo '</form>';
                    echo '</table>';

                    echo '</br>';

                    echo '<table class="table-paint">';
                    for ($i = 0; $i <= $size; $i++) {
                        echo '<tr>';
                        for ($j = 0; $j <= $size; $j++) {
                            if ($i == 0 && $j ==0) {
                                echo '<td></td>';
                            } else if ($i == 0) {
                                $letter = chr($j+64);
                                echo '<td>'.$letter.'</td>';
                            } else if ($j == 0) {
                                echo '<td>'.$i.'</td>';
                            } else {
                                echo '<td class="clickable"></td>';
                            }
                        }
                        echo '</tr>';
                    }
                    echo '</table>';
                }
            ?>
            <?php
                if (isset($error)) {
                    echo '<h2>'.$error.'</h2>';
                    echo '<label for="size">Size: </label>';
                    echo '<input type="text" id="size" name="size" value="">';
                    echo '<label for="color">Color Amount: </label>';
                    echo '<input type="text" id="color" name="color" value="">';
                    echo '<button onclick="update()">Update</button>';
                }
        ?>
        </main>
    </body>

    <footer>
        <h3>LOCAL FUEL</h3>
    </footer>
</html>

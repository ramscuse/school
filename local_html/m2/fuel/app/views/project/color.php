<!DOCTYPE html>
<html>
    <head>
        <style>
            table {
                color: black;
                border: 1px solid;
                border-collapse: collapse;
                width: 100%;
            }
            table, tr, td {
                border: 1px solid;
            }
            .table-color .left{
                width: 20%;
            }
            .table-color .right{
                width: 80%;
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
                padding: 20px 25px;
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
            $("document").ready(() => {
                
            });
        </script>
    </head>

    <header>
        <h1>Color Coordinate Generator</h1>
    </header>

    <body>
        <div class="body">
            <?php
                if (isset($size) && isset($coloramount)) {
                    echo '<label for="size">Size: </label>';
                    echo '<input type="text" id="size" name="size" value="'.$size.'">';
                    echo '<label for="color">Color Amount: </label>';
                    echo '<input type="text" id="color" name="color" value="'.$coloramount.'">';
                    echo '<button onclick="update()">Update</button>';

                    echo '<table class="table-color">';
                    for ($i = 0; $i < $coloramount; $i++) {
                        echo '<tr>';
                        echo '<td class="dropdown">';
                        echo '<div class=dropbtn>Color</div>';
                        echo '<div class="dropdown-content">';
                        foreach ($colors as $name => $val) {
                            echo '<p href="'.$val.'">'.$name.'</p>';
                        }
                        echo '</div>';
                        echo '</td>';
                        echo '<td class="right">selected choice</td>';
                        echo '</tr>';
                    }
                    echo '</table>';

                    echo '</br>';

                    echo '<table>';
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
                                echo '<td>test</td>';
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
        </div>
    </body>

    <footer>
        <h3>LOCAL FUEL</h3>
    </footer>
</html>
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
    </head>

    <header>
        <h1>Color Coordinate Generator</h1>
    </header>

    <body>
        <div class="body">
            <?php
                if (isset($size) && isset($coloramount)) {
                    echo '<p>Size of Table: '.$size.'</p>';
                    echo '<p>Amount of Color Choices: '.$coloramount.'</p>';

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
            <?php echo isset($error) ? '<h2>'.$error.'</h2>' : '' ?>
        </div>
    </body>

    <footer>
        <h3>LOCAL FUEL</h3>
    </footer>
</html>
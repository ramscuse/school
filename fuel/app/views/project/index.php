<!DOCTYPE html>
<html>
    <head>
        <style>
            header img {
                display: block;
                margin-left: auto;
                margin-right: auto;
                width: 800px;
                height: 150px;
            }
        </style>
    </head>

    <header>
        <?php echo Asset::img('logo.png', array('id' => 'logo')); ?>
        <!-- <img src="../assets/img/logo.png" style="object-fit:fill; width:900px; height:300px;" alt="logo"> -->
    </header>

    <body>
        <div>
            <p></p>
            <p>Welcome to Our CS312 Project Home Page</p>
        </div>
    </body>

    <footer>
        <h3>LOCAL FUEL</h3>
    </footer>
</html>
<!DOCTYPE html>
<html>
<head>
<title>Timing System</title>
<link rel="stylesheet" href="main.css">
</head>
<body>

    <header>Add user</header>
    <section>
        <nav>
            <ul>
                <li><a href="database.php">Database</a></li>
                <li><a href="index.php">Home</a></li>
            </ul>
        </nav>

        <article>
            Enter name of the user 
            <form method="POST" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
            <label for="name">Name:</label><br>
                <input type="text" id="name" name="name"><br>
            <input type="submit" id="submit" name="submit">Submit
            </form>
            

            <?php
                if ($_SERVER["REQUEST_METHOD"] == "POST") {
                    $name = $_POST["name"];
                    $res = exec("sudo /bin/bash /home/timing/website/addUser.sh {$name}");
                    if($res == 1){
                        echo "name already exists, try another name!";
                    }else if($res == 2){
                        echo "something wrong with the files";
                    }else if($res == 0){
                        echo $name." added";
                    }
                }


            ?>
        </article>
    </section>
</body>
</html>

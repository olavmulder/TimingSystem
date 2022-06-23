<!DOCTYPE html>
<html>
<head>
<title>Timing System</title>
<link rel="stylesheet" href="main.css">
</head>
<body>

    <header>Timing System</header>
    <section>
        <nav>
            <ul>
                <li><a href="database.php">Database</a></li>
                <li><a href="addUser.php">Add Users</a></li>
            </ul>
        </nav>

        <article>
            Enter name of current runner 
            <form method="POST" action="<?php echo htmlspecialchars($_SERVER["PHP_SELF"]);?>">
                <?php
                    echo '<label for="distance">Distance:</label><br>';
                    echo '<select id="distance" name="distance"><br>';
                    echo '<option value="10">10</option>';
                    echo '<option value="20">20</option>';
                    echo '<option value="30">30</option>';
                    echo '<option value="40">40</option>';
                    echo '<option value="50">50</option>';
                    echo '<option value="60">60</option>';
                    echo '<option value="80">80</option>';
                    echo '<option value="100">100</option></select><br>';
                    

                    echo '<label for="name">Name:</label><br>';
                    echo '<select id="name" name="name"><br>';
                    $file = "/home/timing/RPI/bin/users.txt";
                    $array = explode("\n", file_get_contents($file));
                    foreach($array as $a){
                        echo '<option value='.$a.'>'.$a.'</option>';
                    }
                    echo '</select><br><input type="submit" value="Submit">';
                ?>       
            </form>
            <?php
            $name = NULL;
            if ($_SERVER["REQUEST_METHOD"] == "POST") {
                $name = $_POST["name"];
                $distance = $_POST["distance"];
               
                
                include "getData.php";
                $data = GetDataUser($name);
                $bestTime = GetBestTime($data, $distance);
                echo "best time on ".$distance. "m is ".$bestTime. " <br>"; 
                $currTime = GetCurrentTime();
                echo "<br>Current time:<br>";
                $currTime = number_format($currTime,2);
                echo $currTime;
                
            }
            
            ?>

        </article>
    </section>

</body>
</html> 
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
                <li><a href="addUser.php">Add Users</a></li>
                <li><a href="index.php">Home</a></li>

            </ul>
        </nav>

        <article>
            <?php
            
                $file = fopen("/home/timing/RPI/bin/data.txt", "r");
                $members = array();
                $i=0;
                echo '<table><tr><th>ID</th><th>Name</th><th>Distance</th><th>Estaette</th>';
                echo '<th>Time</th></tr>';
                while (!feof($file)) {
                    $members[] = fgets($file);
                }
                for($i=0;$i<sizeof($members);$i=$i+1){
                    if($members[$i] == "\n"){
                        echo"</tr><tr>";
                    }else{
                        echo "<td>";
                        echo $members[$i];
                        echo "</td>";

                    }
                   
                }
                echo '</tr></table>';
                
                
                fclose($file);
                    
                

            ?>
        </article>
    </section>

</body>
</html> 
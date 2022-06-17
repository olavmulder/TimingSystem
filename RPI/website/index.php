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
                <li><a href="#">Overview</a></li>
                <li><a href="#">Database</a></li>
            </ul>
        </nav>

        <article>
            Enter name of current runner 
            <form action="/nameInput.php">
                <label for="name">Name:</label><br>
                <input type="text" id="name" name="name"><br>
            </form>
            <?php
            include "getData.php";
            echo "<br>Current time:";
            echo "<br>Best time:";

            ?>

        </article>
    </section>

</body>
</html> 
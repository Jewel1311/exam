<?php
    session_start();
    include 'connection.php';
     echo "welcome"." " .$_SESSION['name']."<br><br>";
    $sql = "select * from example1";
    $result = mysqli_query($conn,$sql);
    while($row = mysqli_fetch_assoc($result)){
        echo nl2br("Name"." " .$row['username']." ". "password"." ".$row['password']."\n");
    }

?>

<!DOCTYPE html>
<html lang="en">
<head>
    <meta charset="UTF-8">
    <meta http-equiv="X-UA-Compatible" content="IE=edge">
    <meta name="viewport" content="width=device-width, initial-scale=1.0">
    <title>Document</title>
</head>
<body>
    <br><a href="logout.php">Logout</a>
</body>
</html>
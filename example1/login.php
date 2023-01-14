<?php
    session_start();
    include 'connection.php';
    if(isset($_POST['login'])){
        $uname =  $_POST['uname'];
        $pass = $_POST['pass'];

        $sql = "select * from example1 where username='$uname' and password = '$pass'";
        $result = mysqli_query($conn,$sql);
        if(mysqli_num_rows($result) > 0){
            $_SESSION['name']=$uname;
            header("Location:home.php");
        }
        else{
            echo "user not found";
        }
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
    <h1>Login</h1>
    <form method="post">
        <input type="text" name="uname" placeholder="username"><br>
        <input type="password" name="pass" placeholder="password"><br>
        <input type="submit" value="login" name="login">
    </form>
</body>
</html>
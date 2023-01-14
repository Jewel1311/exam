<?php
    include 'connection.php';
    $uname =  $_POST['uname'];
    $pass = $_POST['pass'];

    $sql = "insert into example1 (username, password) values ('$uname','$pass')";

    if(mysqli_query($conn,$sql)){
        header('Location:login.php');
    }
    else
        echo "error"
?>
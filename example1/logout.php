<?php
    session_start();
    session_destroy();
    header("Location:login.php");

    // to destroy a particular session use 
    // unset($_SESSION['uname']);
?>
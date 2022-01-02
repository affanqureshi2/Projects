<?php
//require_once('roots.php');
//require_once($root_path.'include/config.php');

//session_start();
if (isset($_SESSION['logged_in'])){
session_destroy();
echo '<script>window.location.reload()</script>';
}
echo 'You have been logged out.<br> <a href="'.$root_path.'main.php?page_1">Go to login page</a>';
?>
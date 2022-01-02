 <?php
 
 include("adodb5/adodb.inc.php");
 include("adodb5/tohtml.inc.php");
 include("adodb5/adodb-pager.inc.php");
$servername = "localhost";
$username = "root";
$password = "";
$dbase = "db_office";

// Create connection
$conn = newADOConnection('mysqli');
$conn->connect($servername, $username, $password, $dbase); 
// Check connection
//if (!$db) {
//    die("Connection failed: " . mysqli_connect_error());
//}
?> 
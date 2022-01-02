<?php 
function login_fun(all_data){
$username = $_POST['username'];
$password = $_POST['password'];

echo $_SESSION['logged_in'];

$sql = "select * from tb_employee where username = '$username' and password = '$password'";
$result = mysqli_query($conn,$sql);
$row = mysqli_fetch_array($result,MYSQLI_ASSOC);
echo $sql;
//row["username"];
if ($row["username"] == $username && $row['password'] == $password){
	// header("Location: ".$root_path.'modules/login/view.php');
	echo $row["username"];

	$_SESSION['logged_in'] = $_POST['username'];
	echo '<script type="text/javascript"> window.location.href = "'.$root_path.'modules/login/view.php"; </script>';
}
 ?>
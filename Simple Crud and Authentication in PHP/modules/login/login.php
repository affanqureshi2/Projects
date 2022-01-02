<?php
//session_start();
//require_once('roots.php');
//require_once($root_path.'include/config.php');
//require_once($root_path."include/functions.php");


$log_var=$pass="";

if(isset($_POST['signup'])){
	echo $root_path;
	header("Location: ".$root_path.'main.php?page_1=1');
}
if(isset($_POST['login'])){
	$log_var= $_POST['username'];
	$pass=	$_POST['password'];
	$incorrect = login_fun($_POST);
	//login_fun($_POST);
	//if(!){
	//$incorrect = "Incorrect password or username. Please try again.";
	//}
	}


?>
<HTML>
<head>
<title>Employee Log in</title>
<meta name="viewport" content="width=device-width, initial-scale=1">

<link rel="stylesheet" type="text/css" href="<?php echo $root_path; ?>modules/login/css/login.css">

</head>
<body>
 <form action="main.php?page_1" method="POST">
  <div class="container">
    <h1>Log in</h1>
        

    <label for="username"><b>Username/Email</b></label>
    <input size='60' class='form-control' type="text" placeholder="Enter username or email" name="username" value="<?php echo $log_var; ?>" required>

<br>
	<label for="password"><b>Password</b></label>
    <input size='60' class='form-control' type="password" placeholder="Enter Password" name="password" value="<?php echo $pass; ?>" required>
    <SPAN class="error"><?php if(isset($incorrect)){echo $incorrect;} ?></SPAN>
    <br>
 
    <button style='width: 500' class="btn btn-default" size = '50' name="login">Log in</button>

    <button style='width: 500; float: right;' class="btn btn-default" size = '50' name="signup" formnovalidate>Sign up</button>

  </div>
</form> 

</body>
</html>
   <!--<input type="submit" class="signup" name="login" value="Log in">     <input type="submit" class = "signup" name="signup" value="Sign up" formnovalidate>
   	
<?php 
require_once('roots.php');
require_once($root_path.'include/config.php');

?>
<!DOCTYPE html>
<html>
<head>
<link rel="stylesheet" type="text/css" href="<?php echo $root_path; ?>css/home.css">

</head>
<body>

<!--<div class="header">
  
</div>-->

<ul>
  <li><a class="active" href="<?php echo $root_path; ?>main.php?page_1">Home</a></li>
  <li><a href="<?php echo $root_path; ?>modules/login/edit.php">Signup</a></li>
  <!--<li><a href="#contact">Contact</a></li>-->
</ul>

</body>
</html>
<?php
header("Location: main.php?page_1");
?>
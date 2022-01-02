
<link rel="stylesheet" type="text/css" href="<?php echo $root_path; ?>css/home.css">

<ul id="nav">
<?php 
	if (isset($_SESSION['logged_in'])){
 ?>
 <li><a class="btn" href="<?php echo $root_path; ?>main.php?page_1=4">Home</a></li>
  <li><a class="btn" href="<?php echo $root_path; ?>main.php?page_1=3">Logout</a></li>
  <li><a class="btn" href="<?php echo $root_path; ?>main.php?page_1=2">Display</a></li>
 <?php 
}
else{
  ?>
  <li><a class="btn" href="<?php echo $root_path; ?>main.php?page_1">Home</a></li>


<?php 
}

 ?>
 </ul>
 <script src="<?php echo $root_path;?>js/active.js"></script>

<?php 
require_once("roots.php");
require_once($root_path.'include/config.php');

if(isset($_POST['uploadfilesub']))
{
	$filename = $_FILES['uploadfile']['name'];
	$filetmpname = $_FILES['uploadfile']['tmp_name'];
	$pic_path = $root_path.'pictures/'.$filename;
	move_uploaded_file($filetmpname, $pic_path);
	$sql = 	"INSERT INTO db_pics(pic) values ('$filename')";
	$qry = mysqli_query($conn, $sql);
	if($qry)
	{
		echo "image uploaded";
	}
}

 ?>
 <!DOCTYPE html>
 <html>
 <head>
 	<title></title>
 </head>
 <body>
 <form action = "" method="post" enctype="multipart/form-data">
 	<input type="file" name="uploadfile" />
 	<input type="submit" name="uploadfilesub" value = "upload"/>
 	
 	
 </form>
 </body>
 </html>
<?php
//session_start();
//require_once('roots.php');
//require_once($root_path.'include/config.php');
//require_once($root_path."include/functions.php");


$username = $password = $email = $firstname = $lastname = $country = $city = $textarea = '';
$main_id="";

if(isset($_REQUEST['id']) && $_REQUEST['id']!=""){
	$main_id=$_REQUEST['id'];
	$result = $conn->execute("SELECT * FROM tb_employee where id =". $main_id);
	$row =  $result->FetchRow();
}
else{
	$row = null;
}

if (isset($_SESSION['logged_in']) || empty($main_id))
{


?>
<HTML>
<head>
<?php if(empty($main_id)){
	$title="Employee SignUp Page";
}else{
	$title="Employee Update Page";
} ?>
<title><?php echo $title;?></title>
<?php //if (!empty($main_id)){
//	include($root_path.'include/header.php'); 
//}
	?>

<link rel="stylesheet" type="text/css" href="<?php echo $root_path;?>modules/login/css/edit.css">
  <script src="tinymce/tinymce.min.js" referrerpolicy="origin"></script>
  <script>tinymce.init({selector:'textarea'});</script>

</head>
<script type="text/javascript">
  var root_path="<?php echo $root_path;?>";
</script>
<script src="<?php echo $root_path;?>js/jquery.min.js"></script>
<script src="<?php echo $root_path;?>/modules/registration/js/reg_scripts.js"></script>

</head>
<body>
  <div>
    <?php
$nameErr1= $nameErr2 = $nameErr3 = $nameErr4 = $genderErr1 = $genderErr2 = $emailErr = '';

if(isset($_POST['login_1'])){
      header("Location: ".$root_path.'main.php?page_1');
    }



    $query = $conn->query("Select * from tb_country");
     if (!$query) {
    trigger_error('Invalid query: ' . $conn->error);
}

     $rowCount = $query->recordCount();

      
    if(isset($_POST['create'])){

    	$ret = saveData($_POST,$main_id);
     

      if(!$ret){

      }else{
        echo $ret;
    
    }
}
    ?>
</div>
  
 <form method="POST" class="modal-content" enctype="multipart/form-data" action="<?php $root_path;?>main.php?page_1=1" >

 	<input type="hidden" name="id" value="<?php echo $main_id;?>">
  <div class="container" style="width: 1000px">
    <?php 
    	if(empty($main_id)){
    		$edit = "Sign Up Form";
    	}
    	else{
    		$edit = "Edit Form";	
    	}
     ?>
    <h1><?php echo $edit; ?></h1>
    <p>Please enter the details in this form to update an account.</p>
    <hr>

    <label for="username"><b>Username:</b></label>
    <input style='width: 500;' class='form-control' type="text" placeholder="Enter username" name="username" value="<?php if(!empty($main_id)){
    echo $row['username'];
}
else{echo $username;}
     ?>"required>
    <span class="error">* <?php echo $nameErr1;?></span>
<br>
	<label for="password"><b>Password:</b></label>
  <?php 
 if(!empty($main_id)){
?>
    <input style='width: 500;' class='form-control' type="password" placeholder="<unchange>" name="password" value="">
<?php 
}
else{
       ?>
   <input style='width: 500;' class='form-control' type="password" placeholder="Enter Password" name="password" value="<?php echo $password; ?>" required>
   <?php 
}
    ?>
    <span class="error">* <?php echo $nameErr2;?></span>
<br>
    <label for="email"><b>Email:  &nbsp &nbsp &nbsp &nbsp</b></label>
    <input style='width: 500;' class='form-control' type="text" placeholder="Enter Email" name="email" value="<?php  
     if(!empty($main_id)){
    echo $row['email'];}
    else{echo $email;}
     ?>" required>
    
    <span class="error">* <?php echo $emailErr;?></span>
<br>


<br>
    <label for="firstname"><b>First Name:</b></label>
    <input style='width: 500;' class='form-control' type="text" placeholder="Enter firstname" name="firstname"  value="<?php 
if(!empty($main_id)){
    echo $row['firstname'];}
else{echo $firstname;}
     ?>" required>
    <span class="error">* <?php echo $nameErr3;?></span>

<br>
	<label for="lastname"><b>Last Name:</b></label>
    <input style='width: 500;' class='form-control' type="text" placeholder="Enter lastname" name="lastname"  value="<?php 
if(!empty($main_id)){
    echo $row['lastname'];}
else{echo $lastname;}
     ?>" required>
    <span class="error">* <?php echo $nameErr4;?></span>
<br>
<label for="country"><b>Country:  &nbsp &nbsp</b></label>
<select class="form-control form-control-sm" id="country" class="dropdowns" name="country">
  <option value="<?php $row['country']?>">Select the country</option>
  
  <?php
  if($rowCount > 0){
    while($rowCn = $query->FetchRow()){
    	$selected='';
    	if($rowCn['id']==$row['country']){ $selected=' selected="selected" '; }
      echo '<option value ="'.$rowCn['id'].'" '.$selected.'>'.$rowCn['name'].'</option>';
    }          
  }
  else{
    echo '<option value="">Country not available</option>';
  
  }
  ?>
  
</select>
<span class="error">* <?php echo $genderErr1;?></span>
    
    <br><label for="city"><b> City: &nbsp</b></label>
    <input type="hidden" id="saved_city" value="<?php echo $row['city']; ?>"/>
    <select class="form-control form-control-sm" id="city" name="city">
    </select>

  <span class="error">* <?php echo $genderErr2;?></span>

<br>
<label for="country"><b>Biography:  &nbsp &nbsp</b></label>
<br>
<textarea name="textarea" placeholder="Hello there! Give the brief summary of you achievements" ><?php 
if(!empty($main_id)){
    echo $row['textarea'];}
else{echo $firstname;}
     ?>
  
</textarea>
<br>
<input type="file" name="uploadfile" /><?php 
    	if(!empty($main_id)){
    	?> <img class="img-thumbnail" width=200px height= 200px src="<?php echo $row['picture']; ?>"/>

 <?php 
}
    	if(empty($main_id)){
    		$butn = "Sign Up";
    	}
    	else{
    		$butn = "Update";	
    	}
     ?>
<br>
    <button style='width: 500; ' class="btn btn-default" size = '50' name="create"><?php echo $butn; ?></button>

<?php 
if(empty($main_id)){

	 ?>
  <!--  	
<br>
    <button style='width: 500;' class="btn btn-default" size = '50' name="login_1"  formnovalidate>Log in</button>
<br>
-->
<?php 
}
 ?>

  </div>
</form> 
<br>
  
</body>
</html>
<?php 

}
else{
	echo "Please Log in first.<br> <a href='".$root_path."modules/login/login.php'>Go to login page</a>";
}
 ?>
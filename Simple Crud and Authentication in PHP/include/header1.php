
<link rel="stylesheet" type="text/css" href="<?php echo $root_path; ?>css/header.css">
<link rel="stylesheet" href="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/css/bootstrap.min.css">
<script src="https://ajax.googleapis.com/ajax/libs/jquery/3.4.1/jquery.min.js"></script>
<script src="https://maxcdn.bootstrapcdn.com/bootstrap/3.4.0/js/bootstrap.min.js"></script>
 
<nav class="navbar navbar-default navbar-fixed-top">
  <div class="container">
    <div class="navbar-header">
      <button type="button" class="navbar-toggle" data-toggle="collapse" data-target="#myNavbar">
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>
        <span class="icon-bar"></span>                        
      </button>
      <?php 
      $items = array('4'=>'Home','2'=>'Display');
  if (isset($_SESSION['logged_in'])){
    foreach ($items as $x=>$x_val){
      if ((isset($_REQUEST['page_1'])) && $_REQUEST['page_1']==$x){
 ?>
      <b><a class="navbar-brand" href="<?php echo $root_path; ?>main.php?page_1=<?php echo $x ?>"><?php echo $x_val ?></a></b>
<?php 
}
      else{ ?>
        <a class="navbar-brand" href="<?php echo $root_path; ?>main.php?page_1=<?php echo $x ?>"><?php echo $x_val ?></a>
      <?php
      } 
}
       ?>
    </div>
    <div class="collapse navbar-collapse" id="myNavbar">
      <ul class="nav navbar-nav navbar-right">
        <li><a href="<?php echo $root_path; ?>main.php?page_1=3">LOGOUT</a></li>
        
 <?php 
  
}
else{
  ?>
  <a class="navbar-brand" href="<?php echo $root_path; ?>main.php?page_1">HOME</a>

<?php 
}

 ?>
      </ul>
    </div>
  </div>
</nav>

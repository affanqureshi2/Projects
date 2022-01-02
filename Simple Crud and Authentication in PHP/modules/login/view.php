<script src="https://kit.fontawesome.com/5e88491ee5.js"></script>
<?php
//session_start();
//require_once('roots.php');
//require_once($root_path.'include/config.php');
//require_once($root_path."include/functions.php");
$totalcount = $search = '';
$page = (int)(!isset($_GET["page"]) ? 1 :$_GET["page"]);
//error_log($page);
$limit = 5;
$startpoint = ($page * $limit) - $limit;
//error_log($startpoint);
$statement = "tb_employee order by id asc";
//error_log(print_r($_SESSION,1));
//error("Why I am render");
if (isset($_SESSION['logged_in']))
{
	
	if(isset($_POST['logout'])){
	header('Location:'.$root_path.'modules/login/logout.php');
}


?>
<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN" "http://www.w3.org/TR/html4/strict.dtd">
<html>
<head>
<title>View Records</title>
<script src="<?php echo $root_path;?>/js/jquery.min.js"></script>

<link rel="stylesheet" type="text/css" href="css/pagination.css">
</head>
<body>
<?php


//$delete = mysqli_query($conn,"DELETE FROM tb_employee WHERE id =");
//$result = mysqli_query($conn,"SELECT * FROM tb_employee");
	//For simple project
	$sql1 = "SELECT * FROM {$statement} Limit {$startpoint},{$limit}";
$sql2 = "Select username,email,firstname,lastname,(Select name from tb_country where id = tb_employee.country) as country,(Select name from tb_city where id = tb_employee.city) as city, '' as Edit from tb_employee";
//$pager = new ADODB_Pager($conn,$sql2);

if(isset($_POST['search'])){
//error_log($startpoint);
$page = (int)(!isset($_GET["page"]) ? 1 :$_GET["page"]);
//error_log($page);
$limit = 5;
$startpoint = ($page * $limit) - $limit;
//error_log($startpoint);
$statement = "tb_employee";
	//echo search($_POST);
	$where_clause=" AND (username like '%".$_POST['s_b']."%' or email like '%".$_POST['s_b']."%' or firstname like '%".$_POST['s_b']."%' or lastname like '%".$_POST['s_b']."%' or country LIKE '%".$_POST['s_b']."%' or city like '%".$_POST['s_b']."%') order by id LIMIT {$startpoint},{$limit}";
	//error_log($sql1);
	displaydata($where_clause,$statement);
	//$chk_pagination=1;
	$search = $_POST['s_b'];
}

 // error_log($sql1);
//echo $sql1;
$result = $conn->Execute($sql1);
//$country = mysqli_query($conn,"SELECT name FROM tb_country where id =");
//$city = mysqli_query($conn,"SELECT name FROM tb_city where id =");

echo "<br><form action='#' method='POST' class='form-inline' style='text-align: center;'><div  class='input-group'><input size='60' class='form-control' type='text' name='s_b' value='".$search."' placeholder='Search by username/email/firstname/lastname/country/city'><div class='input-group-btn'><button name='search' class='btn btn-danger'>Search</button></div></div></form><br>";

echo "<table class='table table-striped' border='1' cellpadding='10' id = 'myTable'>";
echo "<tr class='trow'>

<th class='trow' onclick='sortTable(1)'>Username:</th>
<th class='trow' onclick='sortTable(2)'>First Name:</th>
<th class='trow' onclick='sortTable(3)'>Last Name:</th>
<th class='trow' onclick='sortTable(4)'>email:</th>
<th class='trow' onclick='sortTable(5)'>Country</th>
<th class='trow' onclick='sortTable(6)'>City</th>
<th class='trow' >Action</th>

<th class='trow' >Image</th>
</tr>";

while($row =  $result->FetchRow())
{

//.row['id']
echo "<tr>";
echo '<td class="trow">' . $row['username'] . '</td>';
echo '<td class="trow">' . $row['firstname'] . '</td>';
echo '<td class="trow">' . $row['lastname'] . '</td>';
echo '<td class="trow">' . $row['email'] . '</td>';
echo '<td class="trow">' . ($conn->Execute("SELECT name FROM tb_country where id =".$row['country']))->FetchRow()['name'] . '</td>';
echo '<td class="trow">'  . ($conn->Execute("SELECT name FROM tb_city where id =".$row['city']))->FetchRow()['name'] .  '</td>';

$admin = ($conn->Execute("SELECT username FROM tb_employee where Admin = '1'"))->FetchRow()['username'];

if($row['Admin'] != 1 || $admin == $_SESSION['logged_in']){

echo '<td class="trow"><a href="main.php?page_1=1&id=' . $row['id'] . '"><i class="far fa-edit"></i>&nbsp</a>';
}
else{
echo '<td class="trow"><i class="far fa-edit"></i>&nbsp';	
}
//$row['Admin'] != 1 && 
if($row['Admin'] != 1 && $row['username'] != $_SESSION['logged_in']){
echo '&nbsp &nbsp<a href="#" onclick="deleteitems(\''.$row['id'].'\')"><i class="fas fa-trash-alt"></i></a></td>';
}
else if($row['Admin'] != 1 ){
echo '&nbsp &nbsp  <a href="#" onclick="CnAd()" <i class="fas fa-trash-alt"></i></td></a>';	
}
else{
echo '&nbsp &nbsp  <i class="fas fa-trash-alt"></i></td>';	

}
echo '<td class="trow">'?><img class="img-thumbnail" width=100px height= 100px src="<?php echo $row['picture']; ?>"/></td><?php 
echo "</tr> ";
}

echo "</table> ";

echo "<div id='pagingg' >";

//echo pagination($statement,$limit,$page,$totalcount);
echo "</div> <br><br>";


//$pager->Render();
?>
<br>
<!--<form action="#" method="POST">
<input type="submit" name="logout" value="Log out" >-->
<?php 


}
else{
	echo "Please Log in first.<br> <a href='".$root_path."main.php?page_1'>Go to login page</a>";
}

 ?>



</body>
</html>


<script src="<?php echo $root_path;?>modules/login/js/view.js">
</script>
<script type="text/javascript">
	$(document).ready(function() {
		$('table').DataTable();
	});

</script>
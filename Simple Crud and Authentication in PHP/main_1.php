<?php
session_start();
require_once('roots.php');
require_once($root_path.'include/config.php');
require_once($root_path."include/functions.php");
?>
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<?php
 include($root_path."include/header.php");
$include_page="";
if(!isset($_REQUEST['page_1'])){
	$_REQUEST['page_1'] = "2" ;
}

switch($_REQUEST['page_1']){
	case "1":
		$include_page=$root_path."modules/login/edit.php";
		break;
	case "2":
		$include_page=$root_path."modules/login/view.php";
		break;
	case "3":
		$include_page=$root_path."modules/login/logout.php";
		break;
	default:
		$include_page=$root_path."modules/login/Login.php";
	break;
}
if(!empty($include_page)){
	include($include_page);
}
?>
<br>

<?php include($root_path."include/footer.php");?>
</body>
</html>
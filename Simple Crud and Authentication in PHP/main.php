<?php
//session_start();
require_once('roots.php');
require_once($root_path.'include/config.php');
require_once($root_path."include/functions.php");
require_once($root_path."include/libs/Smarty.class.php");

$smarty = new Smarty;
/*
ob_start();
include($root_path."modules/login/login.php");
$login = ob_get_contents();
ob_clean();

ob_start();
include($root_path."modules/login/view.php");
$view = ob_get_contents();
ob_clean();

ob_start();
include($root_path."modules/login/edit.php");
$eidt = ob_get_contents();
ob_clean();

ob_start();
include($root_path."modules/login/logout.php");
$logout = ob_get_contents();
ob_clean();
*/
ob_start();
include($root_path."main_1.php");
$main = ob_get_contents();
ob_clean();

$include_page="";
$page = $_REQUEST['page_1'];

$smarty->assign("header",$head);
// $smarty->assign("login",$login);
// $smarty->assign("view",$view);
// $smarty->assign("edit",$eidt);
// $smarty->assign("logout",$logout);
// $smarty->assign("page_1",$page);
$smarty->assign("content",$main);
$smarty->display('main.tpl');
?>
<!--
<!DOCTYPE html>
<html>
<head>
	<title></title>
</head>
<body>
<?php 
/*
if(!isset($_REQUEST['page_1'])){
	$_REQUEST['page_1'] = "2" ;
}

switch($_REQUEST['page_1']){
	case "1":
		//$include_page=$root_path."modules/login/edit.php";
		break;
	case "2":
		//$include_page=$root_path."modules/login/view.php";
		break;
	case "3":
		//$include_page=$root_path."modules/login/logout.php";
		break;
	default:
		//$include_page=$root_path."modules/login/Login.php";
	break;
}
if(!empty($include_page)){
	include($include_page);
}
*/?>
<br>

</body>
</html>-->
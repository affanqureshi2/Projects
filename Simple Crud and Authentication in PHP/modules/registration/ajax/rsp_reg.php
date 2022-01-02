<?php
require_once("roots.php");
require_once($root_path."include/config.php");
if(isset($_REQUEST['task'])){
	switch ($_REQUEST['task']) {
		case "getCity":
			echo getCity();
			break;
		case "delete":
      echo deleteEmployee();
      break;
		default:
			# code...
			break;
	}
}
function getCity(){
	global $conn;
  $city="";
  if(isset($_REQUEST['city']) && $_REQUEST['city']!=""){
    $city=$_REQUEST['city'];
  }
	$result='
  <option value="">Select City</option>';
  $query = $conn->Execute("Select id,name from tb_city where country = ".$_REQUEST['id']);
     if (!$query) {
    trigger_error('Invalid query: ' . $db->error);
}
     $rowCount = $query->RecordCount();
  if($rowCount > 0){
    while($row = $query->FetchRow()){
      $selected='';
      if($row['id']==$city){ $selected=' selected="selected" '; }
      $result.= '<option value ="'.$row['id'].'" '.$selected.'>'.$row['name'].'</option>';
    }
  }
  else{
    $result.= '<option value="">City not available</option>';
  
  }
  return $result;
}

function deleteEmployee(){
  global $conn;
  //echo $_REQUEST['id'];
  $query = $conn->query("DELETE FROM tb_employee where id =".$_REQUEST['id']);
}
?>
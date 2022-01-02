<?php
require_once("roots.php");
require_once($root_path."include/config.php");
if(isset($_REQUEST['task'])){
	switch ($_REQUEST['task']) {
		case "getCity":
			echo getCity();
			break;
		
		default:
			# code...
			break;
	}
}
function getCity(){
	global $conn;
	$result='
  <option value="">Select City</option>';
  $query = $conn->execute("Select id,name from tb_city where country = ".$_REQUEST['id']);
    
     $rowCount = $query->RecordCount();
  if($rowCount > 0){
    while($row = $query->FetchRow()){
      $result.= '<option value ="'.$row['id'].'">'.$row['name'].'</option>';
    }
  }
  else{
    $result.= '<option value="">City not available</option>';
  
  }
  return $result;
}
?>
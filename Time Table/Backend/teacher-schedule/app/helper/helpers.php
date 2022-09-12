<?php

function successData($data,$message,$code=200){
    $result = array();
    $result['code'] = $code;
    $result['status'] = true;
    $result['message'] = $message;
    $result['data'] = $data;
    $result_json = json_encode($result);
    return $result_json;
}
function errorData($message,$code=500){
    $result = array();
    $result['code'] = $code;
    $result['status'] = false;
    $result['message'] = $message;
    $result['data'] = "";
    $result_json = json_encode($result);
    return $result_json;
}
?>
<?php
function search($all_data){
  global $conn, $result, $sql1;
  if(!empty($all_data['s_b'])){
  $sql1 = 'SELECT * FROM tb_employee where username='.$all_data['s_b'].' or email ='.$all_data['s_b'];
  $result = $conn->Execute($sql1);
  return false;
  }
  else{
    return $sql1;
  }
}


function test_input($data)
{
   $data = trim($data);
   $data = stripslashes($data);
   $data = htmlspecialchars($data);
   return $data;
}
function saveData($all_data,$main_id){
      global $conn,$_SESSION, $root_path, $row, $nameErr1, $nameErr2, $nameErr3, $nameErr4, $emailErr, $genderErr1, $genderErr2, $username, $password, $email, $country, $firstname, $lastname, $city, $textarea;

      
     // $username = $all_data['username'];
  
   
 //   $sql_e = "SELECT * FROM tb_employee WHERE email='$email'";
 
//    $res_e = mysqli_query($conn, $sql_e);


if ($_SERVER["REQUEST_METHOD"] == "POST") {

      $filename = $_FILES['uploadfile']['name'];
      $filetmpname = $_FILES['uploadfile']['tmp_name'];
     
     if(!empty($main_id) && !isset($filename)){
      $pic_path = $row['picture'];
  }
  else{
      $pic_path = $root_path.'pictures/'.$filename;
    
  }
   move_uploaded_file($filetmpname, $pic_path);
    

    if (empty($all_data['username'])) {
    $nameErr1 = "userame is required \n";
  } 
  else {
    $username = test_input($all_data["username"]);
    // check if name only contains letters and whitespace
    $sql_u = "SELECT * FROM tb_employee WHERE username='$username'";
    $res_u = $conn->execute($sql_u);
    if ($res_u->RecordCount() > 0 && $res_u->FetchRow()['username'] != $row['username']) {
    //  $nameErr1 = $res_u->fetch_assoc()['password'];
      $nameErr1 = "Sorry... username already taken \n";  
    }
    else if (!preg_match("/^[a-zA-Z ]*$/",$username)) {
      $nameErr1 = "Only letters and white space allowed \n";
    }
  }
//      $password = $all_data['password'];

  if (empty($all_data['password']) && empty($main_id)) {
    $nameErr2 = "Password is required \n";
  } 
  
  else if (empty($all_data['password']) && !empty($main_id)){
    $password = ($conn->Execute("Select * from tb_employee where username ='$username'"))->FetchRow()['password'];
  }
  else {
    $password = test_input($all_data['password']);
  
    $uppercase = preg_match('@[A-Z]@', $password);
    $lowercase = preg_match('@[a-z]@', $password);
    $number    = preg_match('@[0-9]@', $password);
  
   if(strlen($password) < 6) {
  $nameErr2 = "Password must have length greater than 5 \n";
}
  else if(!$uppercase || !$lowercase || !$number){
    $nameErr2 = "Password must contain a number and one uppercase and one lowercase character";
  
  }
  //$password = md5($password);
  }

 //     $email = $all_data['email'];
   if (empty($all_data['email'])) {
    $emailErr = "Email is required \n";
  } 
 //   else if(mysqli_num_rows($res_e) > 0){
   //   $emailErr = "Sorry... email already taken"; 
   // }
  else {
    $email = test_input($all_data['email']);
    // check if e-mail address is well-formed
    $sql_e = "SELECT * FROM tb_employee WHERE email='$email'";
    $res_e = $conn->Execute($sql_e);
    
    if($res_e->RecordCount() > 0 && $res_e->FetchRow()['email'] != $row['email']){
      $emailErr = "Sorry... email already taken \n"; 
    }
    else if (!filter_var($email, FILTER_VALIDATE_EMAIL)) {
      $emailErr = "Invalid email format \n";
    }
  }
  //    $firstname = $all_data['firstname'];
  if (empty($all_data['firstname'])) {
    $nameErr3 = "firstname is required \n";
  } 
  else {
    $firstname = test_input($all_data['firstname']);
    // check if name only contains letters and whitespace
    if (!preg_match("/^[a-zA-Z ]*$/",$firstname)) {
      $nameErr3 = "Only letters and white space allowed \n";
    }
  }

//      $lastname = $all_data['lastname'];
    if (empty($all_data['lastname'])) {
    $nameErr4 = "lastname is required \n";
  } else {
    $lastname = test_input($all_data['lastname']);
    // check if name only contains letters and whitespace
    if (!preg_match("/^[a-zA-Z ]*$/",$lastname)) {
      $nameErr4 = "Only letters and white space allowed \n";
    }
  }
//      $city = $all_data['city'];

  if (empty($all_data['city'])) {
    $genderErr2 = "City is required ";
  } else {
    $city = test_input($all_data['city']);
  }
 //     $country = $all_data['country'];

  if (empty($all_data['country'])) {
    $genderErr1 = "Country is required ";
  } else {
    $country = test_input($all_data['country']);
  }

  $textarea = test_input($all_data['textarea']);
}
if($nameErr1 || $nameErr2 || $nameErr3 || $nameErr4 || $emailErr || $genderErr1 || $genderErr2){

}

else{
      //echo $username . " " . $password . " " . $email . " " . $firstname . " " . $lastname;
     //$sql = "INSERT INTO tb_employee (username, password, email, firstname, lastname, picture, city, country ) VALUES(?,?,?,?,?,?,?,?)";
      //$stmt = $conn->prepare($sql);
      //$stmt->bind_param("ssssssss", $username, $password , $email, $firstname, $lastname,$file, $city, $country);
  $main_query = " SET username='$username', password=md5('$password'), email='$email', firstname='$firstname', lastname='$lastname', picture='$pic_path', city='$city', country='$country', textarea='$textarea' ";
      if(!empty($main_id)){
      $sql = "UPDATE tb_employee ".$main_query." WHERE id =".$main_id;
      }
      else{
        $sql = "INSERT INTO tb_employee ".$main_query;
      }
      $result = $conn->Execute($sql);

      if($result && !empty($main_id)){
        echo "Successfully Updated.";
        header("Location: main.php?page_1=2");
      }
      else if ($result && empty($main_id)) {
       // echo "Successfully Saved.";
       // session_start();
        error_log($username);
          $_SESSION['logged_in'] = $username;
          echo "Successfully Saved.";
          header("Location:main.php?page_1=4");
        //echo '<script type="text/javascript"> window.location.href = "'.$root_path.'main.php?page_1=4"; </script>';
       // header("Location: main.php?page_1");
      }
      else{
        //echo $sql;
        echo "Something Wrong. Please check the code.";
      }
      
     }
  //  $stmt->close();
  //  $conn->close();
    }


function login_fun($all_data){
      global $conn,$root_path,$_SESSION;
      $username = $all_data['username'];
      $password = md5($all_data['password']);
      $sql = "select * from tb_employee where (username = '$username' or email = '$username') and password = '$password'";

      $result = $conn->Execute($sql);
      $row = $result->FetchRow();
       //error_log($row['password']);
      // $username;
      if (($row["username"] == $username || $row["email"]== $username) && $row['password'] == $password){
        //|| $row["email"]== $username
        // header("Location: ".$root_path.'modules/login/view.php');
        $_SESSION['logged_in'] = $row['username'];
        //echo $_SESSION['logged_in'];
        echo '<script type="text/javascript"> window.location.href = "'.$root_path.'main.php?page_1=4"; </script>';
        
      }
      else{
    //    return false;
     //   return $row['password'];
         return "Incorrect password or username. Please try again.";
      // //  login($incorrect);
      // //  header("Location: ".$root_path.'modules/login/login.php');  
      //   return $incorrect;
        }   
}

function displayData($where_clause=""){
  global $sql1,$totalcount;
  $sql1="SELECT * FROM tb_employee WHERE 1=1";
  $totalcount = "SELECT count(*) as `num` FROM tb_employee WHERE 1=1";
  if(!empty($where_clause)){
    $sql1.=$where_clause;
    error_log($sql1.'hello');
    $totalcount.=$where_clause;
  }
  
}

  function pagination($query, $per_page = 10,$page = 1, $totalcount, $url = '?'){ 
      global $conn;
//      error_log('{$url}');
   if($totalcount==''){
      $query = "SELECT COUNT(*) as `num` FROM {$query}";
      
    }
    else{
     $query = $totalcount; 
    // error_log($query);
    }
      $result = $conn->Execute($query);
      $row = $result->FetchRow();

      $total = $row['num'];
        $adjacents = "2"; 

      $page = ($page == 0 ? 1 : $page);  
   //   error_log($page);
      $start = ($page - 1) * $per_page;               

      $prev = $page - 1;              
      $next = $page + 1;
        $lastpage = ceil($total/$per_page);
      $lpm1 = $lastpage - 1;
      
      $pagination = "";
      if($lastpage > 1)
      { 
        
        $pagination .= "<ul class='pagination'>";
          $pagination .= "<li class='details' style='margin-top:2px'>Page $page of $lastpage</li>";

      if ($page != $start+1){
          $pagination.= "<li><a href='{$url}page_1=2&page=1'>First</a></li>"; 
          $pagination.= "<li><a href='{$url}page_1=2&page=$prev'>Prev</a></li>";
                
        }else{
          $pagination.= "<li><a class='current'>First</a></li>";
          $pagination.= "<li><a class='current'>Prev</a></li>";
           
            }
 

        if ($lastpage < 7 + ($adjacents * 2))
        { 
          for ($counter = 1; $counter <= $lastpage; $counter++)
          {

            if ($counter == $page)
              $pagination.= "<li><a class='current'>$counter</a></li>";
            else
              $pagination.= "<li><a href='{$url}page_1=2&page=$counter'>$counter</a></li>";          
          }
        }
        elseif($lastpage > 5 + ($adjacents * 2))
        {
          if($page < 1 + ($adjacents * 2))    
          {
            for ($counter = 1; $counter < 4 + ($adjacents * 2); $counter++)
            {
              if ($counter == $page)
                $pagination.= "<li><a class='current'>$counter</a></li>";
              else
                $pagination.= "<li><a href='{$url}page_1=2&page=$counter'>$counter</a></li>";          
            }
            $pagination.= "<li class='dot'>...</li>";
            $pagination.= "<li><a href='{$url}page_1=2&page=$lpm1'>$lpm1</a></li>";
            $pagination.= "<li><a href='{$url}page_1=2&page=$lastpage'>$lastpage</a></li>";    
          }
          elseif($lastpage - ($adjacents * 2) > $page && $page > ($adjacents * 2))
          {
            $pagination.= "<li><a href='{$url}page_1=2&page=1'>1</a></li>";
            $pagination.= "<li><a href='{$url}page_1=2&page=2'>2</a></li>";
            $pagination.= "<li class='dot'>...</li>";
            for ($counter = $page - $adjacents; $counter <= $page + $adjacents; $counter++)
            {
              if ($counter == $page)
                $pagination.= "<li><a class='current'>$counter</a></li>";
              else
                $pagination.= "<li><a href='{$url}page_1=2&page=$counter'>$counter</a></li>";          
            }
            $pagination.= "<li class='dot'>..</li>";
            $pagination.= "<li><a href='{$url}page_1=2&page=$lpm1'>$lpm1</a></li>";
            $pagination.= "<li><a href='{$url}page_1=2&page=$lastpage'>$lastpage</a></li>";    
          }
          else
          {
            $pagination.= "<li><a href='{$url}page_1=2&page=1'>1</a></li>";
            $pagination.= "<li><a href='{$url}page_1=2&page=2'>2</a></li>";
            $pagination.= "<li class='dot'>..</li>";
            for ($counter = $lastpage - (2 + ($adjacents * 2)); $counter <= $lastpage; $counter++)
            {
              if ($counter == $page)
                $pagination.= "<li><a class='current'>$counter</a></li>";
              else
                $pagination.= "<li><a href='{$url}page_1=2&page=$counter'>$counter</a></li>";          
            }
          }
        }
        
        if ($page < $counter - 1){ 
          $pagination.= "<li><a href='{$url}page_1=2&page=$next'>Next</a></li>";
                $pagination.= "<li><a href='{$url}page_1=2&page=$lastpage'>Last</a></li>";
        }else{
          $pagination.= "<li><a class='current'>Next</a></li>";
                $pagination.= "<li><a class='current'>Last</a></li>";
            }
          $strc = $start+1;
          $ltrc = $start+5;
        $pagination.= "<li>$strc - $ltrc of $total</li>";    
        $pagination.= "</ul>\n";    
      }
       return $pagination;
    } 
?>
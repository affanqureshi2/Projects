  $(document).ready(function(){
    $('#country').on('change',loadCity);
    loadCity();
  });

function loadCity(){
      countryID = $("#country").val();
      var all_data='task=getCity&id='+countryID;
      if($("#saved_city").val()!=""){
        all_data+='&city='+$("#saved_city").val();
      }
      if(countryID){
        $.ajax({
          type:'POST',
          url:root_path+'/modules/registration/ajax/rsp_reg.php',
          data:all_data,
          success:function(html){
            $('#city').html(html);
          }
        });
      
      }
      else{
        $('#city').html('<option value="">Select country first</option>');
      }
}
  $(document).ready(function(){
    loadCity();
    $('#country').on('change',loadCity());
  });

function loadCity(){
      countryID = $(this).val();
      
      if(countryID){
        $.ajax({
          type:'POST',
          url:root_path+'/modules/registration/ajax/rsp_reg.php',
          data:'task=getCity&id='+countryID,
          success:function(html){
            $('#city').html(html);
          }
        });
      
      }
      else{
        $('#city').html('<option value="">Select country first</option>');
      }
}
<?php include('header.php'); ?>

<section>
	<div class="container">
		<div class="card text-center">
			<div class="card-body bg-light">
				<h3 class="card-title text-muted">Schedule of teacher:</h3>
			</div>
			<div class="card-body p-5">
				<?php
				$api_url = "http://localhost:8000/teacher";
				$json_data = file_get_contents($api_url);
				$response_data = json_decode($json_data);
				$teacher_data = $response_data->data;
				
				?>
				<label for="mySelectBox">Select Teacher:</label>
				<select id="mySelectBox" class="form-control">
				<option ></option>
				<?php foreach($teacher_data as $teacher){
					?>
					<option value="<?=$teacher->id;?>"><?=$teacher->name;?></option>
					<?php }?>
				</select>
				<table id="schedule" class="table table-striped table-bordered table-hover dataTables-wo text-center">
					<thead>
						<tr>
							<th>Class</th>
							<th>Subject</th>
							<th>Timing</th>
							<th>Duration(min)</th>
						</tr>
					</thead>
					<tbody id="tbodyid"></tbody>
				</table>
			</div>
		</div>
	</div>
</section>
<script>
// 	$(document).ready(function () {
//     $('#schedule').DataTable({
// 		ajax:
// 		{
// 			"url": "http://localhost:8000/period",
// 		},
// 		"columns": [
//                     { "data": "classes.name" },
//                     { "data": "subject.name" },
//                     { "data": null,"render": function ( data, type, row ) { return data.start_time +' - '+ data.end_time; } },                       
//                     { "data": "duration" }
//             ]
// 	}
// 		);
// });
$(document).ready(function () {
	var teachers;
    $.ajax({
        url: "http://localhost:8000/period",
        cache: false,
        success: function(data){
          teachers = JSON.parse(data);
        }
      });

    $('#mySelectBox').on("change",function(){
      $("#tbodyid").empty();
	  let i = 0;
        (teachers.data).forEach(function(item) {
            // do something with `item`
			console.log($('#mySelectBox').find(":selected").val());
            if($('#mySelectBox').find(":selected").val() == item.teacher_id)
            {
              $("#tbodyid").append('<tr><td>'+item.classes.name+'</td><td>'+item.subject.name+'</td><td>'+item.start_time +' - '+ item.end_time+'</td><td>'+item.duration+'</td></tr>');  
			  if(i == 1)
			  	$("#tbodyid").append('<tr><td colspan=4>Break & Teacher Meeting</td></tr>');
            }
			i++;  
          });
		  $("#tbodyid").append('<tr><td colspan=4>off</td></tr>');
    })
  });
</script>
<?php include('footer.php'); ?>
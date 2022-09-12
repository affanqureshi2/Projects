<?php include('header.php'); 
$api_url = "http://localhost:8000/teacher";
$json_data = file_get_contents($api_url);
$response_data = json_decode($json_data,true);
$teachers = $response_data['data'];
$class = array(1=>"I",2=>"II",3=>"III");
$subject = array(1=>"Science",2=>"Maths",3=>"English");

?>
<link rel="stylesheet" href="./css/theme2.css"/>

<section>
	<div class="container">
		<div class="card text-center">
			<div class="card-body bg-light">
				<h3 class="card-title text-muted">Add Schedule:</h3>
			</div>
			<div class="card-body p-4 border-bottom">
			<form id="teacher" action="" method="POST">
				<div class="form-group">
					<label for="name">Teacher</label>
					<select name="teacher_id" class="form-control">
						<?php 
							foreach($teachers as $teacher)
							{
						?>
						<option value="<?=$teacher["id"];?>"><?=$teacher["name"];?></option>
						<?php } ?>
					</select>
				</div>
				<div class="form-group">
					<label for="Qualification">Subject</label>
					<select name="subject_id" class="form-control">
						<?php 
							foreach($subject as $key=>$teacher)
							{
						?>
						<option value="<?=$key;?>"><?=$teacher;?></option>
						<?php } ?>
					</select>
				</div>
				<div class="form-group">
					<label for="Qualification">Class</label>
					<select name="class_id" class="form-control">
						<?php 
							foreach($class as $key=>$teacher)
							{
						?>
						<option value="<?=$key;?>"><?=$teacher;?></option>
						<?php } ?>
					</select>
				</div>
				<div class="form-group">
					<label for="startTime">Start Time</label>
					<input type="time" class="form-control" id="startTime" name="start_time">
				</div>
				<div class="form-group">
					<label for="endtime">End Time</label>
					<input type="time" class="form-control" id="endTime" name="end_time">
				</div>
				<button type="submit' class="btn btn-primary">Submit</button>
				</form>
			</div>
		</div>
		</div>
	</div>
</section>
<script>
	$(document).ready(function (e) {
		$('#teacher').submit( function (e) {

			var data= $("#teacher").serialize();
			console.log(data);
			$.ajax({
			type: 'post',
			url: 'http://localhost:8000/period-add',
			data: data,
			dataType: 'json',
			success: function () {
				toastr.success('Period Added Successfully!');
			}
			}).fail(function (jqXHR, textStatus) {
				toastr.error('Required Data missing');
			}
			);
			e.preventDefault();
			});
			
});
</script>
<?php include('footer.php'); ?>
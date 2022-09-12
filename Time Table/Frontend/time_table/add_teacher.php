<?php include('header.php'); ?>

<section>
	<div class="container">
		<div class="card text-center">
			<div class="card-body bg-light">
				<h3 class="card-title text-muted">Add Teacher:</h3>
			</div>
			<div class="card-body p-4 border-bottom">
			<form id="teacher" action="" method="POST">
				<div class="form-group">
					<label for="name">Name</label>
					<input type="text" class="form-control" id="name" placeholder="Enter Teachers Name" name="name">
				</div>
				<div class="form-group">
					<label for="Qualification">Qualification</label>
					<input type="text" class="form-control" id="qualification" placeholder="Qualification" name="qualification">
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
</section>
<script>
	$(document).ready(function (e) {
		$('#teacher').submit( function (e) {

			var data= $("#teacher").serialize();
			$.ajax({
			type: 'post',
			url: 'http://localhost:8000/teacher-add',
			data: data,
			dataType: 'json',
			success: function () {
				toastr.success('Teacher Added Successfully!');
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
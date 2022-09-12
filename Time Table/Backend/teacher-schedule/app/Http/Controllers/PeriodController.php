<?php

namespace App\Http\Controllers;

use App\Models\Period;
use App\Models\Teacher;
use App\Models\Subject;
use App\Models\Classes;
use Illuminate\Http\Request;

class PeriodController extends Controller
{
    /**
     * Create a new controller instance.
     *
     * @return void
     */
    public function __construct()
    {
        //
    }

    public function index(){
        $result = array();
        $period = Period::with(["subject","classes"])->get();
        return successData($period,"Data Send Succesfully");
    }

    public function create(Request $request){
        $data = $request->all();

        $this->validate($request, [
            'teacher_id' => 'required',
            'class_id' => 'required',
            'subject_id' => 'required',
            'end_time' => 'required',
            'start_time' => 'required'
        ]);
        $period = new Period();
        $data["duration"] = ((int)$data["end_time"] -  (int)$data["start_time"])*60; 
        $period = $period->create($data);
        return successData($period,"Period Added Successfully",201);
    }

    public function getFilters(){
        $teacher = Teacher::get();
        $subject = Subject::get();
        $class = Classes::get();
        $result_data = array();
        $result_data['teacher'] = $teacher;
        $result_data['subject'] = $subject;
        $result_data['class'] = $class;
        return successData($result_data,"Period Added Successfully",201);
    }
}

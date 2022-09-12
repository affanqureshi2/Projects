<?php

namespace App\Http\Controllers;

use App\Models\Teacher;
use Illuminate\Http\Request;

class TeacherController extends Controller
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
        $teacher = Teacher::get();
        return successData($teacher,"Data Send Succesfully");
    }

    public function create(Request $request){
        $data = $request->all();

        $this->validate($request, [
            'name' => 'required',
            'qualification' => 'required',
            'start_time' => 'required',
            'end_time' => 'required'
        ]);
        $teacher = new Teacher();
        $teacher = $teacher->create($data);
        return successData($teacher,"Teacher Added Successfully",201);
    }
}

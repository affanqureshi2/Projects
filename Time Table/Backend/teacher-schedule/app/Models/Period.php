<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Period extends Model
{
    protected $table = "period";
    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'teacher_id', 'class_id','subject_id','start_time','duration','end_time'
    ];

    protected $hidden = ['created_at','updated_at','deleted_at'];

    protected $primaryKey = 'id';

    public function subject(){
        return $this->hasOne(Subject::class,"id","subject_id");
    }
    public function classes(){
        return $this->hasOne(Classes::class,"id","class_id");
    }

}

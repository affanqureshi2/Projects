<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Teacher extends Model
{
    protected $table = "teacher";
    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'name', 'qualification','start_time','end_time'
    ];
    protected $hidden = ['created_at','updated_at','deleted_at'];

    protected $primaryKey = 'id';

}

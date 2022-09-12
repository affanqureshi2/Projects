<?php

namespace App\Models;

use Illuminate\Database\Eloquent\Model;

class Classes extends Model
{
    protected $table = "class";
    /**
     * The attributes that are mass assignable.
     *
     * @var array
     */
    protected $fillable = [
        'value', 'name'
    ];
    protected $hidden = ['created_at','updated_at','deleted_at'];

    protected $primaryKey = 'id';

}

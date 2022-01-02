int revNum(int v1)
{

    int out = 0;
    int temp;
 while(v1 != 0)
    { 
    temp = v1 % 10;
    v1 /=  10;
    out =  (out * 10) + temp;
     }
     return out;
}


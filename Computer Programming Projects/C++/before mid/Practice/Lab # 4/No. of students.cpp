#include <iostream>
using namespace std;
int main()
{
	int stu,grade[4],sub,avg,a;
	stu=1;
	while (stu<=5)
	{
	cout<<"Roll No."<<stu<<endl;
	sub = 1;
	avg = 0;
	while(sub<=4)
	{
		cout<<"Sub "<<sub<<"\t";
		cin>>grade[sub];
		sub++;
	}
	for(int x=1;x<=4;x++)
		avg=avg + grade[x];
		a=avg/4;
	cout<<"Average of student # "<<stu<<"\t"<<a<<endl;
	stu++;
}
	return 0;
}


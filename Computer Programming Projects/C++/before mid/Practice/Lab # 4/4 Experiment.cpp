#include <iostream>
using namespace std;
int main()
{
	int exp;
	float res[6],avg,a;
	exp = 1;
	while(exp<=4)
	{
		cout<<exp<<" experiment results: ";
		for(int x=0;x<=5;x++)
		{cin>>res[x];
		cout<<" ";
		}
		for(int b=1;b<=6;b++)
		avg=avg+res[b];
		a=avg/6;
		cout<<"Average of "<<exp<<" experiment = "<<a;
		cout<<endl;
		exp++;
	}
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a,b,c,d;
	a=1;
	b=1;
	c=1;
	d=1;
	while(a<=10)
	{
	b=a*a;
	cout<<b<<endl;
	a=a+1;
	}
	while(c<=10)
	{
		d=c*c*c;
		cout<<d<<endl;
		c++;
	}
	return 0;
}

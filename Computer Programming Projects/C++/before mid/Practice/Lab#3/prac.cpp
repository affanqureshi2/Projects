#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	int a,b,c;
	a=1;
	c=30;
	while(a<=2)
	{
		b=1;
		cout<<setw(c);
		while(b<=a)
		{
		cout<<"*"<<endl;
		c=c-5;
		b=b+1;}
	
	c=c-5;
	a++;	
	}
}


#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	a=0;
	c=20;
	while(a<=9)
	{
		b=0;
		cout<<setw(c);
		while(b<=a)
		{
			cout<<"*";
			b++;
		}
		
		cout<<"\n";
		c--;
		a=a+2;
	}
}

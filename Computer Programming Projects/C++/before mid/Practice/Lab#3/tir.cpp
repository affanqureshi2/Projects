#include <iostream>
#include <cstdlib>
#include <iomanip>
using namespace std;
int main()
{
	int a,b,c;
	a=1;
	while(a<=7)
	{
		b=1;
		c=20;
		cout<<setw(c);
		while(b<=a)
		{
		cout<<"*"<<"\t";
		b=b+1;
		
		}
		c=c-6;
		cout<<"\n";
		
		a=a+2;
		
		}
	}


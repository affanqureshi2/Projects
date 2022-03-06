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
		
		
		while(b<=a)
		{
		cout<<setw(10)<<"*"<<"\t";
		
		b++;
		}
		
		cout<<"\n";
		a++;
		
		}
	}


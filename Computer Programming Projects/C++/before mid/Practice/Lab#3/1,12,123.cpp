#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	a=1;
	while(a<=5)
	{
		b=1;
		c=1;
		
		while(b<=a)
		{
		cout<<c<<"\t";
		c=c+1;
		b++;
		}
		
		cout<<"\n";
		a++;
		
		}
	}


#include <iostream>
#include <iomanip>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	a=8;
	c=1;
	
	while(a>=0)
	{
		b=a;
		
		cout<<setw(c);
		
		while(b>=0)
		{
			cout<<"*";
			b--;
		}
		
		cout<<"\n";
		c++;
		a=a-2;
	}
}

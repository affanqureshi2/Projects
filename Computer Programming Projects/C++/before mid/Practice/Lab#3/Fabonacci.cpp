#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	a=0;
	b=1;
	c=0;
	while(c<=200)
	{	
		
		
		cout<<c;
		c=b+a;
		if(c<200)
		cout<<",";
		else
		cout<<"";
		a=b;
		b=c;
		
	}
}	

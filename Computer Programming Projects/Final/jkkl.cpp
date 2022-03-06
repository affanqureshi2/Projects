#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,c;
	a=0;
	b=1;
	c=1;
	while(c<=200)
	{	
		
		
		cout<<c;
		c=c+a;
		if(c<200)
		cout<<",";
		else
		cout<<"";
		a=c;
		;
		
	}
}	

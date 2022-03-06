#include <iostream>
using namespace std;
int main()
{
	float c=0,n=1;
	
	while(n<=45)
	{
		c=c+(1/n);
		n++;
	}
	cout<<c<<endl;
}

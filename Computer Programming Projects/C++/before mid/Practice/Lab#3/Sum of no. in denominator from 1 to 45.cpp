#include <iostream>
using namespace std;
int main()
{
	double a,c;
	a=2;
	c=1;
	while(a<=45)
	{
		c=c+(1/a);
		a++;
	}
	cout<<c<<endl;
}

#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int x,fac;
	fac = 1;
	cin>>x;
	while(x>1)
	{
		fac=fac*x;
		x--;
	}
	cout<<fac<<endl;
}

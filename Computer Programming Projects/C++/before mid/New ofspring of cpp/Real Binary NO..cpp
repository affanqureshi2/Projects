#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,r,z;
	z=0;
	cin>>a;
	r=a;
		while(a!=0)
	{
	
	a=a/2;
	z++;
	}
	z=z-1;
	a=r;
	int i=0;
	int x[z];
		while(a!=0)
	{
	x[i]=a%2;
	a=a/2;
	i++;
	}
	
	for (i=z;i>=0;i--)
	cout<<x[i];
	cout<<endl;
	
	return 0;
}

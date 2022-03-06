#include<iostream>
using namespace std;
int fac(int x)
{
	if(x>1)
	return fac(x-1)*x;
	else
	return 1;
}
int main()
{
	
	cout<<fac(5)<<endl;
}

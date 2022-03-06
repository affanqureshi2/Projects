#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a,x,b;
	cin>>a;

	while(a!=0)
	{
	x=a%2;
	a=a/2;
	cout<<x;
	}
	cout<<"\n";
	cout<<x<<endl;
	
	
	system("pause");
	return 0;
}

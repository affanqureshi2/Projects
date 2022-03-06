#include <iostream>
using namespace std;
int fact(int n)
{
	int ans;
	if(n>1)
	{
		return fact(n-1)*n;
	}
	else
	{
		return 1;
	}
	cout<<ans<<endl;
}
int main()
{
	int a;
	cin>>a;
	cout<<fact(a);
}

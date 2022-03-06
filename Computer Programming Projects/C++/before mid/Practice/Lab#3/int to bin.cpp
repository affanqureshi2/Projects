#include <iostream>
using namespace std;
int main()
{
	int x,n;
	cin>>x;
	while(x!=0)
	{
		n=x%2;
		x=x/2;
		cout<<n;
	}
	
}

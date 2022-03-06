#include <iostream>
using namespace std;
int main()
{
	int n,c;
	cin>>n;
	c=1;
	while(n!=1)
	{
		c=c*n;
		n--;
	}
	cout<<c<<endl;
	return 0;
}

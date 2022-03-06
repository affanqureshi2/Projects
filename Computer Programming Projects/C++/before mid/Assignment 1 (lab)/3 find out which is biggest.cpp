#include <iostream>
using namespace std;
int main()
{
	int x,y,z;
	cin>>x;
	cin>>y;
	cin>>z;
	if (x>y && x>z)
	cout<<x<<endl;
	else if (y>x && y>z)
	cout<<y<<endl;
	else
	cout<<z<<endl;
	return 0;
}

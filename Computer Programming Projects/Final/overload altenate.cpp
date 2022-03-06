#include<iostream>
using namespace std;
template <typename z>
z min (z &a,z &b)
{
	if (a<b)
		return a;
	else
		return b;
}
int main()
{
	int a,b;
	cin>>a;
	cin>>b;
	cout<<min(a,b)<<endl;
}

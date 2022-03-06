#include<iostream>
using namespace std;
int main()
{
	int i;
	cin>>i;
	for (int x=1;x<=i;x++)
	{
	int *ptr = new int;
	ptr = i;
	cout<<*ptr;
}
}

#include<iostream>
using namespace std;
int main()
{
	int i;
	cin>>i;
	int n=1;
	int *ptr = new int[i];
	while (n!=4)
	{
	*ptr=n;
	cout<<*ptr<<endl;
	n=n+1;
}
}

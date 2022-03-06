#include <iostream>
using namespace std;
int main()
{
	int n1,n2,a,s,m,d,r;
	cout<<"Enter the first number = ";
	cin>>n1;
	cout<<"Enter the second number = ";
	cin>>n2;
	a = n1 + n2;
	s = n1 - n2;
	m = n1 * n2;
	d = n1 / n2;
	r = n2 % n1;
	cout<<"Addition of "<<n1<<" and "<<n2<<" is "<<a<<endl;
	cout<<"Subtraction of "<<n1<<" and "<<n2<<" is "<<s<<endl;
	cout<<"Multipication of "<<n1<<" and "<<n2<<" is "<<m<<endl;
	cout<<"Division of "<<n1<<" and "<<n2<<" is "<<d<<endl;
	cout<<"Modulus of "<<n1<<" and "<<n2<<" is "<<r<<endl;
	return 0;
}

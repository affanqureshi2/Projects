#include <iostream>
using namespace std;
int main()
{
	double b,h,m,c,t;
	cout<<"Enter the basic pay = ";
	cin>>b;
	cout<<"Home = ";
	h= .45*b;
	cout<<h<<endl;
	cout<<"Medical Budget = ";
	if(b>5000)
	{
	m= .2*b;
	cout<<m<<endl;}
	else
	{
	m=.1*b;
	cout<<m<<endl;}
	cout<<"Conveyance = ";
	if(b>5000)
	{
	c=5000;
	
	cout<<c<<endl;}
	else
	{
	c=1000;
	cout<<c<<endl;}
	cout<<"Net Pay = ";
	t= b+h+m+c;
	cout<<t<<endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int y,d;
	cout<<"Enter the age in year : ";
	cin>>y;
	d = y * 365 + (y % 4);
	cout<<"\n\nAge in days : "<<d<<endl;
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	double length,width,area,perimeter;
	cout<<"Enter the value of length = ";
	cin>>length;
	cout<<"\nEnter the value of width = ";
	cin>>width;
	perimeter = 2 * (length + width);
	area = length * width;
	cout<<"\nArea = "<<area;
	cout<<"\nPerimeter = "<<perimeter;
	return 0;
}

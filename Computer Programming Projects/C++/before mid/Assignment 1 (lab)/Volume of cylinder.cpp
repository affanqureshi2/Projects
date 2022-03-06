#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	int r,h,v,pi;
	cout<<setw(50)<<"PROGRAM FOR VOLUME OF CYLINDER"<<endl;
	cout<<"Radius of cylinder = ";
	cin>>r;
	cout<<"Height of cylinder = ";
	cin>>h;
	pi = 3.14;
	v = pi*h*(r^2);
	cout<<"Volume of cylinder = "<<v<<endl;
	return 0;
}

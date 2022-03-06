#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int a,b,c,t;
	cout<<"Enter the value of Electricity unit = ";
	cin>>a;
	if(a<=300)
		cout<<"Bill = "<<(a*3)<<endl;
	else
		b = a*3.5;
		c = b*5/100;
		t = b + c;
		cout<<"Total Bill = "<<t<<endl;
	system("pause");
	return 0;
	
	
	}


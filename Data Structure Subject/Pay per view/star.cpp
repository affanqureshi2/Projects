#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	int x,y,z;
	x = 0;
	z=15;
	while(x<=8)
	{
		y=0;
		cout<<setw(z);
		while(y<=x)
	{	cout<<"*";
		y++;
	}
		cout<<endl;
		z= z-1;
		x=x+2;
	}
}

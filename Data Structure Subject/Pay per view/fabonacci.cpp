#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
int main()
{
	int x,y;
	x=0;
	y=1;
	while(y<=200)
	{
		cout<<y<<"\t";
		y=y+x;
		x=y-x;
	}
	return 0;
}

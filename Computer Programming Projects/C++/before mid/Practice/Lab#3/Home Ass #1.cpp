#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	double A,B;
	int y;
	A=5000;
	B=8000;
	y=0;
	while(A<B)
	{
		A=A+((A*4)/100);
		B=B+((B*2)/100);
		y++;
	}
	cout<<y<<endl;
	return 0;
}	

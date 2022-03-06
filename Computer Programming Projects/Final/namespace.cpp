#include<iostream>
using namespace std;
namespace yet
{
	void disp()
	{
		cout<<"surprise mf"<<endl;
	}
}
namespace bet
{
	void disp()
	{
		cout<<"hey buddy"<<endl;
	}
}
using namespace bet;
int main()
{
	disp();
	return 0;
}



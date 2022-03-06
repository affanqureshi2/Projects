#include<iostream>
using namespace std;
namespace myns
{
	void disp()
	{
		cout << "This is my namespace" << endl;

	}
};;
namespace good
{
	void disp()
	{
		cout << "I am good" << endl;

	}
};;
namespace bad
{
	void disp()
	{
		cout << "I am bad" << endl;

	}
};;
using namespace bad; //only one namespace for one program
void main()
{
	disp();
	system("pause");
}

#include <iostream>
using namespace std;
int sum(int x,int y);
int main()
{
	cout<<sum(3,4.5);
	return 0;
	
}
int sum(int x,int y)
{
	return static_cast<float>(x+y);
}

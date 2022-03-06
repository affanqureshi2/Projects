#include<iostream>
#include<string>


using namespace std;

//int max(int a, int b);
int max(int a, int b)
{
	if (a > b)
		return a;
	else if (b > a)
		return b;
	else
		return a;
};

int main()
{
	cout<<max(4,3)<<endl;

}

#include<iostream>
using namespace std;
writ(int n)
{
	if (n<10)
	{
		cout<<n<<endl;
	}
	else
	{
		writ(n/10);
		cout<<n%10<<endl;	
	}
}
int main()
{
	writ(4234);
}

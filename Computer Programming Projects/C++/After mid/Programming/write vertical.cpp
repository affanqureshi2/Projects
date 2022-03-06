#include <iostream>
using namespace std;

int wv(int n)
	{
	
	if(n<10)
	{
		cout<<n<<endl;
	}
	else
	{
		wv(n/10);
		cout<<n%10<<endl;
	}
}
int main()
{
	int a;
	cin>>a;
	wv(a);

}


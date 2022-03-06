#include <iostream>
using namespace std;
int main()
{
	int a,b,c;
	cin>>a;
	b=1;
	c=0;
	while(b<=a)
	{
		if(a%b==0)
		c++;
		b++;
	}
	if(c>2)
	cout<<"No. is not prime"<<endl;
	else if(c<=2)
	cout<<"No. is prime"<<endl;
	return 0;
}

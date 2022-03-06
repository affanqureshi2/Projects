#include <iostream>
using namespace std;
int main()
{
	int s,n,count;
	s = 0;
	n = 1;
	count = 1;
	while (count <= 10)
	{
		s=s+n;
		cout<<n<<endl;
		n=n+2;
		count++;
		
	}
	cout<<"Sum = "<<s<<endl;
}

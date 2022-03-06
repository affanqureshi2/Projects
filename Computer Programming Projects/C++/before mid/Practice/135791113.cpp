#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int u,i,n;
	u = 1;
	while(u<=3)
	{
		i=1;
		n=1;
		while(i<=5)
		{
			cout<<n<<"\t";
			n+=u;
			i+=1;
		}
	cout<<endl;
	u+=1;
		
	}
	system("pause");
	return 0;
}

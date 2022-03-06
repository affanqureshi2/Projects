#include <iostream>
using namespace std;
int main()
{
	int u,i,z;
	u = 1;
	while (u<4)
	{	cout<<"\t";
		i=1;
		z=1;
		while(i<6)
		{
			cout<<"\t"<<z;
			z=z+u;
			i++;
		}
		cout<<endl;
		u++;
	}
}

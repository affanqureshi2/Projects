#include<iostream>
using namespace std;
int main()
{
	/*int e = 1;
	for(int i=0;i<5;i++)
		{
		for(int j=0;j<=i;j++)
			{
			cout<<e<<"\t";
			e++;
		}
		cout<<endl;
	}*/
	int e = 1;
	int i = 0;
	while (i<5)
	{
		int j=0;
		while (j<=i)
		{	
			cout<<e<<"\t";
			e++;
			j++;
		}
		cout<<endl;
		i++;
	}
	return 0;		
}

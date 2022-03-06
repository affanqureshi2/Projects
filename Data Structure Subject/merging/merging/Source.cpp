#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a[10] = { 2, 5, 9, 12, 15, 18, 19, 21, 98, 555 };
	int b[10] = { 1, 4, 8, 11, 16, 22, 25, 35, 68, 102 };
	int c[20];
	int NA = 0;
	int NB = 0;
	int PTR = 0;
	while ((NA<10)&&(NB<10))
	{
		if ((a[NA] < b[NB]) || (a[NA] == b[NB]))
		{
			c[PTR] = a[NA];
			cout << c[PTR]<<endl;
			NA=NA+1;
			PTR = PTR + 1;
		}
		else
		{
			c[PTR] = b[NB];
			cout << c[PTR] << endl;
			NB = NB + 1;
			PTR = PTR + 1;
		
		}
	
		}
	if (NA < 10)
	{
		for (int i = NA; i < 10 ; i++)
		{

			c[PTR] = a[i];

			cout << c[PTR ] << endl;
			PTR = PTR + 1;

		}
	}
	else
	{
		for (int i = NB; i < 10 ; i++)
		{

			c[PTR ] = b[ i];

			cout << c[PTR] << endl;
			PTR = PTR + 1;


		}
	}

	
	system("pause");
	return 0;
	}

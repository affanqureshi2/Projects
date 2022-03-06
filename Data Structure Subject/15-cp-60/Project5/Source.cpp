#include<iostream>
using namespace std;
int main()
{
	int a[5], b[5], c[10];
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	for (int i = 0; i < 5; i++)
	{
		cin >> b[i];
	}
	int i = 0; int y;
	while (i < 10)
	{

		if (i == 0)
		{
			if (a[i] < b[i])
			{
				c[i] = a[i];
				y = b[i];
			}
			else if (a[i]>b[i])
			{
				c[i] = b[i];
				y = a[i];
			}
		}
		else if (y == a[i-1])
		{
			if (y < b[i])
			{
				c[i] = y;
				y = b[i];
			}
			else
			{
				if (a[i] < b[i])
				{
					c[i] = a[i];
					y = b[i];
				}
				else if (a[i]>b[i])
				{
					c[i] = b[i];
					y = a[i];
				}
			}
		}
		else if (y == b[i-1])
		{
			if (y < a[i])
			{
				c[i] = y;
				y = a[i];
			}
			else
			{
				if (a[i] < b[i])
				{
					c[i] = a[i];
					y = b[i];
				}
				else if (a[i]>b[i])
				{
					c[i] = b[i];
					y = a[i];
				}
			}
		}
		i++;
	}
	for (int j = 0; j < 10; j++)
	{
		cout << c[j] << endl;
	}
	system("pause");
}

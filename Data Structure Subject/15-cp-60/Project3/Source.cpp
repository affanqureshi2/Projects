#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;
int main()
{
//	srand(time(NULL));
	int a, end, beg, ans, mid;
	int r[10];

	end = 9; beg = 0; a = 25; ans = 0;
	for (int i = 0; i<10; i++)
	{
		int temp = rand() % 10;
		if (i>0)
			r[i] = r[i - 1] + temp;
		else
			r[i] = temp;
		cout << r[i] << endl;
	}
	cout << endl << endl;
	int i =0;
	while (i < 10)
	{
		mid = (end + beg) / 2;
		if (a == r[mid])
		{
			cout << "Found" << endl;
			cout << "No. of iterations " << i+1 << endl;
			break;
		}
		else if (i != 9)
		{
			
			if (a > r[mid])
			{
				beg = mid + 1;
			}
			else if (a < r[mid])
			{
				end = mid - 1;
			}

		}
		else
		{
			cout << "Not Found" << endl;
		}
		i++;
	}
	system("pause");
}
#include<iostream>
#include<cstdlib>
#include<time.h>

using namespace std;
int main()
{
	srand(time(NULL));
	int a, end, beg, ans, mid;
	int r[11];
	
	end = 0; beg = 0; a = 52; ans = 0;
	for (int i = 0; i<11; i++)
		{
			int temp = rand() % 10;
			if (i>0)
				r[i] = r[i - 1] + temp;
			else
				r[i] = temp;
			cout << r[i] << endl;
		}
	cout << endl << endl;
	int i;
	while(i < 11)
	{
		if (a == r[i])
		{
			cout << "Found" << endl;
			break;
		}
		else if (i!=10)
		{
			mid = (end + beg) / 2;
			if (a > mid)
			{
				beg = mid + 1;
			}
			else if (a < mid)
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

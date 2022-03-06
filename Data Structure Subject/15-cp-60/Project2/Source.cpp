#include<iostream>
#include<cstdlib>
using namespace std;
int main()
{
	int a, end, beg, ans, mid;
	int r[100];
	r[100] = rand() % 10;
	end = 0; beg = 0; a = 10; ans = 0;
	for (int n = 0; n<100; n++)
	{
		cout << r[n] << endl;
	}
	for (int i = 0; i < 100; i++)
	{
		if (a == r[i])
		{
			return a;
			cout << "Found" << endl;
			break;
		}
		else
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
	}
}
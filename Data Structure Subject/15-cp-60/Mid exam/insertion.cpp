#include<iostream>
using namespace std;
int main()
{
	int A[4] = {54,63,32,48};
	int n = 4;
	for(int i = n; i>=0;i++)
	{
		int v = A[i];
		int h = i;
		while (h>0 && A[h-1]>v)
		{
			A[h] = A[h-1];
			h = h-1;
		}
		A[h] = v;
	}
	for (int i = 0;i<n;n++)
	cout<<A[i]<<endl;
}

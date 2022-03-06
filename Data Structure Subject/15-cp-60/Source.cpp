#include<iostream>

#include<cstdlib>

using namespace std;

void insertionsort(int A[], int n)
{
	for (int i = 1; i <= n - 1; i++)
	{
		int value = A[i];
		int hole = i;

		while (hole > 0 && A[hole - 1] > value)
		{
			A[hole] = A[hole - 1];
			hole = hole - 1;
		}
		A[hole] = value;
	}
}

int main()
{
	int A[] = { 1, 5, 6, 78, 3, 77, 67, 89, 9, 0, 4, 3 };
	int n = sizeof(A) / sizeof(*A);

	insertionsort(A, n);

	for (int i = 0; i < n; i++)
	{
		cout << A[i] << endl;
	}
	system("pause");

	return 0;
}
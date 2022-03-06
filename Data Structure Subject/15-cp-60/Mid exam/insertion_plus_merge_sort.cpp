#include<iostream>
using namespace std;

void Merge(int A[], int B[], int C[], int N, int M, int &K);

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
	int C[200], i, n, m, k;

/*	cout << "\nEnter number of elements you want to insert in first array ";
	cin >> n;

	cout << "Enter element in ascending order\n";
	for (i = 0; i<n; i++)
	{
		cout << "Enter element " << i + 1 << ":";
		cin >> A[i];
	}

	cout << "\nEnter number of elements you want to insert in second array ";
	cin >> m;

	cout << "Enter element in descending order\n";
+	for (i = 0; i<m; i++)
	{
		cout << "Enter element " << i + 1 << ":";
		cin >> B[i];
	}
*/
	n = 24;m = 14;
	int A[100] = {76,38,40,26,86,96,34,94,106,102,8,80,28,100,64,98,82,74,104,24,70,68,72,36};
	int B[100] = {37,27,45,79,03,107,87,85,83,93,47,101,57,89};
	int y = 0; int l = 0;
	/*while (A[y] != 0)
		{
		n = n+l;
		y++;
	}
	while (B[l] != 0)
		{
		m = m+l;
		l++;
	}*/
	Merge(A, B, C, n, m, k);
	cout << "\nThe Merged Array in Ascending Order" << endl;
	for (i = 0; i<k; i++)
	{
		cout << C[i] << " ";
	}
	int t = m+n;
	insertionsort(C, t);
	cout<<endl;
	for (int i=0;i<t;i++)
	{
		cout<<C[i]<<" ";
	}

	system("pause");
}


void Merge(int A[], int B[], int C[], int N, int M, int &K)
{
	int I = 0, J = M - 1;
	K = 0;

	while (I<N && J >= 0)
	{
		if (A[I]<B[J])
			C[K++] = A[I++];
		else if (A[I]>B[J])
			C[K++] = B[J--];
		else
		{
			C[K++] = A[I++];
			J--;
		}
	}

	for (int T = I; T<N; T++)
		C[K++] = A[T];
	for (int T = J; T >= 0; T--)
		C[K++] = B[T];
}

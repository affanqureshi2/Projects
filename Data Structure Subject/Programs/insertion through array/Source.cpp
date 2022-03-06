#include <iostream>
using namespace std;
void insertion(int a[], int ln);
void deletion(int a[], int ln);

int main()
{
	int arr[10] = { 1, 2, 3, 4, 5,6,7 };
	cout << "A list contain five elements. And you have capacity of containing 10 elements."<<endl;
	for (int i = 0; i < 10; i++)
	{
		cout << arr[i] << " ";
	}
	cout << endl;
ab:
	{
		int y;
		cout << "Press 1 for insertion" << endl;
		cout << "Press 2 for Deletion" << endl;
		cout << "Press 3 for Deletion" << endl;
		cin >> y;
		if (y == 1)
		{
			insertion(arr, 10);
			goto ab;
		}
		else if (y == 2)
		{
			deletion(arr, 10);
			goto ab;
		}
		else if (y == 3)
		{
			exit;
		}
		else
		{
			cout << "Please press the valid key" << endl;
			goto ab;
		}
	}
	system("pause");
}

void insertion(int a[], int ln)
{
	char y;
	do{
		if (a[ln - 1] != 0)
		{
			cout << "List is full" << endl;
			break;
		}
		cout << "On which place of list you want to insert data" << endl;

		int t,j, h;
		cin >> j;
		for (t = 0; t < ln; t++)
		{
			if (a[t] == 0)
			{
				h = t;
				break;
			}
		}
		
		int i;
		i = h - 1;
		while (h != j - 1)
		{
			a[h] = a[i];
			i--;
			h--;
		}
		cout << "Which element you want to store" << endl;
		cin >> a[j-1];
		cout << "Your new list is given below :" << endl;
		for (int i = 0; i < ln; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << "Do you want to store another element. Press 'y' for yes or 'n' for no ";
		cin >> y;
	} while (y == 'y' || y == 'Y');
}
void deletion(int a[], int ln)
{
	char y;
	do{
		
		cout << "On which place of list you want to delete data" << endl;

		int t, j, h,i;
		cin >> j;
		for (t = 0; t < ln; t++)
		{
			if (a[t] == 0)
			{
				h = t - 1;
				i = t - 2;
				break;
			}
		}

		while (h != j-1 )
		{
			a[i] = a[h];
			i--;
			h--;
		}
		for (int t = 0; t < ln; t++)
		{
			if (a[t] == 0)
			{
				a[t-1] = 0;
				break;
			}
		}

		cout << "Your new list is given below :" << endl;
		for (int i = 0; i < ln; i++)
		{
			cout << a[i] << " ";
		}
		cout << endl;
		cout << "Do you want to delete another element. Press 'y' for yes or 'n' for no ";
		cin >> y;
	} while (y == 'y' || y == 'Y');
}
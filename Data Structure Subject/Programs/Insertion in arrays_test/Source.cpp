#include <iostream>
#include <string>
using namespace std;
void insertion(int a[],int ln);
int main()
{
	int arr[10] = { 1, 2, 3, 4, 5 };
	cout << "An array contain five elements. And you have capacity of containing 10 elements.";
	for (int i = 0; i < 5; i++)
	{
		cout<<arr[i]<<" ";
	}
	cout << endl;
	insertion(arr,10);
}
void insertion(int a[],int ln)
{
	char y;
	do{
		cout << "On which place you want to insert data" << endl;
		
		int j,h;
		cin >> j;
		for (int i = 0; i < ln; i++)
		{
			if (a[i] == 0)
			{
				h = i;
				break;
			}
		}
		int i;
		i = h - 1;
		while (h != j)
		{
			a[h] = a[i];
			i--;
			h--;
		}
		cout << "Which element you want to store" << endl;
		cin >> a[j];
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
#include<iostream>
using namespace std;

int main()
{
	int a[5], b[5],c[10];
	cout << "Enter the first array" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> a[i];
	}
	cout << "Enter the second array" << endl;
	for (int i = 0; i < 5; i++)
	{
		cin >> b[i];
	}
	cout << "Merge form of First and second array" << endl;
	int y = 0;
	int t = 0;
	int i = 0;
	while (i<11)
	{
			c[i] = a[i-t];
			c[i + 1] = b[i-t];
			t++;
			i = i + 2;
	}
	for (int i = 0; i < 10; i++)
	{
		cout << c[i] << endl;
	}
}

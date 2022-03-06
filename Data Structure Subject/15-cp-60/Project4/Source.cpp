#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<iomanip>

using namespace std;
int main()
{
	srand(time(NULL));

	int u = 0;
	int sum = 0;
	int c = 0;
	int avg;
	int end, beg, mid;
	do{
		int key = rand() % 545;

		cout << "Key is " << key << endl;
		cout << endl << endl;

		int n[100];
		end = 99; beg = 0;
		//		cout << "Array of 10 no. is " << endl;
		for (int i = 0; i<100; i++)
		{
			int temp = rand() % 10;
			if (i>0)
				n[i] = n[i - 1] + temp;
			else
				n[i] = temp;
			//	cout << r[i] << endl;
		}

		//		cout <<n[99]<< endl << endl << endl;

		int y = 0;
		while (y < 100)
		{
			mid = (end + beg) / 2;
			if (key == n[mid])
			{
				cout << "Found" << endl;
				int i = y + 1;
				cout << "No. of iteration occurs = " << i << endl;
				sum = sum + i;
				c++;
				break;
			}
			else if (y != 99)
			{

				if (key > n[mid])
				{
					beg = mid + 1;
				}
				else if (key < n[mid])
				{
					end = mid - 1;
				}

			}
			else
			{
				cout << "Not Found" << endl;
				cout << "No. of iteration occurs = " << y + 1 << endl;
			}
			y++;
		}

		cout << endl << "Total sum of iterations  =  " << sum << endl;
		cout << "Total number of iterations  =  " << c << endl;

		cout << endl << endl << setw(20) << "---------" << endl;
		u++;
	} while (u <= 30);
	avg = sum / c;
	cout << endl << endl;
	cout << "Average Number of iterations =  " << avg << endl << endl << endl;

	u = 0;
	char y;
	cout << "Do you want to proceed for 500. y for yes /n for no." << endl;
	cin >> y;
	if (y == 'y')
	{
		int u = 0;
		int sum = 0;
		int c = 0;
		int avg;
		end = 499; beg = 0;
		do{
			int key = rand() % 2300;

			cout << "Key is " << key << endl;
			cout << endl << endl;

			int n[500];
			//		cout << "Array of 10 no. is " << endl;
			for (int i = 0; i<500; i++)
			{
				int temp = rand() % 10;
				if (i>0)
					n[i] = n[i - 1] + temp;
				else
					n[i] = temp;
				//	cout << n[i] << endl;
			}


			//			cout <<n[499]<< endl << endl << endl;

			int y;
			for (y = 0; y < 500; y++)
			{
				mid = (end + beg) / 2;
				if (key == n[mid])
				{
					cout << "Found" << endl;
					int i = y + 1;
					cout << "No. of iteration occurs = " << i << endl;
					sum = sum + i;
					c++;
					break;
				}
				else if (y != 499)
				{

					if (key > n[mid])
					{
						beg = mid + 1;
					}
					else if (key < n[mid])
					{
						end = mid - 1;
					}

				}
				else
				{
					cout << "Not Found" << endl;
					cout << "No. of iteration occurs = " << y + 1 << endl;
				}
			}
			cout << endl << "Total sum of iterations  =  " << sum << endl;
			cout << "Total number of iterations  =  " << c << endl;

			cout << endl << endl << setw(20) << "---------" << endl;
			u++;
		} while (u < 100);
		avg = sum / c;
		cout << endl << endl;
		cout << "Average Number of iterations =  " << avg << endl;
	}
	/*	char ch;
	cout << "Do you want to proceed for 1000. y for yes /n for no." << endl;
	cin >> ch;
	if (ch == 'y')
	{
	int u = 0;
	int sum = 0;
	int c = 0;
	int avg;
	do{
	int key = rand() % 4750;

	cout << "Key is " << key << endl;
	cout << endl << endl;

	int n[1000];
	//		cout << "Array of 10 no. is " << endl;
	for (int i = 0; i<1000; i++)
	{
	int temp = rand() % 10;
	if (i>0)
	n[i] = n[i - 1] + temp;
	else
	n[i] = temp;
	//	cout << n[i] << endl;
	}


	//						cout <<n[999]<< endl << endl << endl;

	int y;
	for (y = 0; y < 1000; y++)
	{
	if (n[y] == key)
	{
	cout << "found" << endl;
	int i = y + 1;
	cout << "No. of iteration occurs = " << i << endl;
	sum = sum + i;
	c++;
	break;
	}
	else if (y == 999)
	{
	cout << "Not found" << endl;
	cout << "No. of iteration occurs = " << y + 1 << endl;
	break;
	}
	}
	cout << endl << "Total sum of iterations  =  " << sum << endl;
	cout << "Total number of iterations  =  " << c << endl;

	cout << endl << endl << setw(20) << "---------" << endl;
	u++;
	} while (u <= 150);
	avg = sum / c;
	cout << endl << endl;
	cout << "Average Number of iterations =  " << avg << endl;
	}
	char ch1;
	cout << "Do you want to proceed for 2000. y for yes /n for no." << endl;
	cin >> ch1;
	if (ch1 == 'y')
	{
	int u = 0;
	int sum = 0;
	int c = 0;
	int avg;
	do{
	int key = rand() % 9200;

	cout << "Key is " << key << endl;
	cout << endl << endl;

	int n[2000];
	//		cout << "Array of 10 no. is " << endl;
	for (int i = 0; i<2000; i++)
	{
	int temp = rand() % 10;
	if (i>0)
	n[i] = n[i - 1] + temp;
	else
	n[i] = temp;
	//	cout << n[i] << endl;
	}


	cout << n[1999] << endl << endl << endl;

	int y;
	for (y = 0; y < 2000; y++)
	{
	if (n[y] == key)
	{
	cout << "found" << endl;
	int i = y + 1;
	cout << "No. of iteration occurs = " << i << endl;
	sum = sum + i;
	c++;
	break;
	}
	else if (y == 1999)
	{
	cout << "Not found" << endl;
	cout << "No. of iteration occurs = " << y + 1 << endl;
	break;
	}
	}
	cout << endl << "Total sum of iterations  =  " << sum << endl;
	cout << "Total number of iterations  =  " << c << endl;

	cout << endl << endl << setw(20) << "---------" << endl;
	u++;
	} while (u <= 300);
	avg = sum / c;
	cout << endl << endl;
	cout << "Average Number of iterations  =  " << avg << endl;
	}
	char ch2;
	cout << "Do you want to proceed for 5000. y for yes /n for no." << endl;
	cin >> ch2;
	if (ch1 == 'y')
	{
	int u = 0;
	int sum = 0;
	int c = 0;
	int avg;
	do{
	int key = rand() % 9200;

	cout << "Key is " << key << endl;
	cout << endl << endl;

	int n[2000];
	//		cout << "Array of 10 no. is " << endl;
	for (int i = 0; i<2000; i++)
	{
	int temp = rand() % 10;
	if (i>0)
	n[i] = n[i - 1] + temp;
	else
	n[i] = temp;
	//	cout << n[i] << endl;
	}


	cout << n[1999] << endl << endl << endl;

	int y;
	for (y = 0; y < 2000; y++)
	{
	if (n[y] == key)
	{
	cout << "found" << endl;
	int i = y + 1;
	cout << "No. of iteration occurs = " << i << endl;
	sum = sum + i;
	c++;
	break;
	}
	else if (y == 1999)
	{
	cout << "Not found" << endl;
	cout << "No. of iteration occurs = " << y + 1 << endl;
	break;
	}
	}
	cout << endl << "Total sum of iterations  =  " << sum << endl;
	cout << "Total number of iterations  =  " << c << endl;

	cout << endl << endl << setw(20) << "---------" << endl;
	u++;
	} while (u <= 750);
	avg = sum / c;
	cout << endl << endl;
	cout << "Average Number of iterations  =  " << avg << endl;
	}
	system("pause");
	*/
}
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
	int y[10000];
	for (int i = 0; i < 50000; i++)
	{
		y[i] = rand() % 1000;
		cout << y[i] << endl;
	}	

	system("pause");

}

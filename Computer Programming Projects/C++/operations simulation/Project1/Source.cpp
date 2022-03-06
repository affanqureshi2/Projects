#include<iostream>
#include<conio.h>
#include<iomanip>
#include <stdlib.h> 
using namespace std;
int main(){
	int arr[20][4];
	for (int i = 0; i < 20; i++){
		arr[i][0] = (rand() % 100) + 1;
		arr[i][1] = (rand() % 100) + 1;
		arr[i][2] = (rand() % 5) + 1;
	}
	for (int i = 0; i<20; i++){
		switch (arr[i][2]){
		case 1:
			arr[i][3] = arr[i][0] + arr[i][1];
			break;
		case 2:
			arr[i][3] = arr[i][0] - arr[i][1];
			break;
		case 3:
			arr[i][3] = arr[i][0] * arr[i][1];
			break;
		case 4:
			arr[i][3] = arr[i][0] / arr[i][1];
			break;
		case 5:
			arr[i][3] = arr[i][0] % arr[i][1];
			break;
		}

	}
	cout << "First Num\tSecond Num\tOperation" << endl;

	for (int i = 0; i < 20; i++){
		for (int j = 0; j < 3; j++){
			cout << arr[i][j] << "\t\t";
		}
		cout << endl;
	}
	for (int x = 0; x<20; x++)
	{
		int i;
		cout << "Enter the no. of line whose Result you want to show" << endl;
		cin >> i;
		cout << "First Num\tSecond Num\tOperation\tResult" << endl;
		cout << arr[i - 1][0] << "\t\t" << arr[i - 1][1] << "\t\t" << arr[i - 1][2] << "\t\t" << arr[i - 1][3] << endl;

	}
	system("pause");
	return 0;
}
#include<iostream>
#include<conio.h>
using namespace std;
int main(){
	int arr[4][4];
	for (int i = 0; i < 4; i++){
		arr[i][0] = rand() % 100;
		arr[i][1] = rand() % 100;
		arr[i][2] = rand() % 100;
	}
	for (int i = 0; i < 4; i++){
		for (int j = 0; j < 4; j++){
			cout << arr[i][j] << "\t"; 
		}
		cout << endl;
	}
	return 0;
}
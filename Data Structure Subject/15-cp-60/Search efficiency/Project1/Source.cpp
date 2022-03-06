#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<iomanip>
#include<string>
using namespace std;
int main()
{
	srand(time(NULL));
	int u= 0;
	int sum = 0;
	int c = 0;
	do{
	int key = rand()%50;
	
	cout<<"Key is "<<key<<endl<<endl<<endl;
	int n[10];
	
	
	cout << "Array of 10 no. is " << endl;
	for (int i=0;i<10;i++)
	{
		int temp = rand()%10;
		if(i>0)
		n[i] = n[i-1] + temp;
		else
		n[i] = temp;
		cout<<n[i]<<endl;
	}
	cout<<endl<<endl<<endl;
	
	int y;
	for (y=0;y<10;y++)
	{
		if(n[y] == key)
		{
			cout<<key<<endl;
			int i = y + 1;
			cout<<"No. of iteration occurs = "<<i<<endl;
			sum = 
			c++;
		break;
		}
		else if (y == 9)
		{
			cout<<"Not found"<<endl;
			cout<<"No. of iteration occurs = "<<y+1<<endl;
			break;
		}
	}
	cout << endl << endl << setw(20) <<"---------"<< endl;
	u++;
	}while(u <= 5);
	system("pause");

}
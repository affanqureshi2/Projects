#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>
#include <cstdlib>
using namespace std;
class tef
{
	string nam,c_titl;
	int sem;
	
	int arr1[3];
	int arr2[5];
	string arr3[3];
	int a,b,c;
	public:
		
		void input()
		{	cout<<"Name of instructor : ";
				
			cout<<"The instructor arrive on time = ";
			cin>>arr1[0];
			if (arr1[0]== 1 || arr1[0]== 2 || arr1[0]== 3 || arr1[0]== 4 || arr1[0]== 5)
				a = arr1[0];
				else
				{
				cout<<"Please enter the correct marks"<<endl;
				}
			cout<<"The instructor leave on time = ";
			cin>>arr1[1];
			if (arr1[1]== 1 || arr1[1]== 2 || arr1[1]== 3 || arr1[1]== 4 || arr1[1]== 5)
				b = arr1[1];
				else
				{
				cout<<"Please enter the correct marks"<<endl;
				}
			cout<<"The instructor prepared for each class = ";
			cin>>arr1[2];
			if (arr1[2]== 1 || arr1[2]== 2 || arr1[2]== 3 || arr1[2]== 4 || arr1[2]== 5)
				c = arr1[2];
				else
				{
				cout<<"Please enter the correct marks"<<endl;
				}	
			
			
		}
		void display()
		{	
			
			for (int j=0;j<=2;j++)
			cout<<arr3[j]<<arr1[j]<<endl;
			
		}
	
};
int main()
{
	tef cp;
	//cp.att();
	cp.input();
	//cp.display();
}


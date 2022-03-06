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
	public:
		void att()
		{	ifstream infile;
			infile.open("mid.txt");
			for (int v=0;v<=2;v++)
				while (!infile.eol())
				infile>>arr3[v];
		}
		void input()
		{
			for (int i=0;i<=2;i++)
			{
				cout<<arr3[i];
				cin>>arr2[i];
				if (arr2[i]== 1 || arr2[i]== 2 || arr2[i]== 3 || arr2[i]== 4 || arr2[i]== 5)
				arr1[i] = arr2[i];
				else
				{
				cout<<"Please enter the correct marks"<<endl;
				i--;
				}
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
	cp.att();
	cp.input();
	//cp.display();
}


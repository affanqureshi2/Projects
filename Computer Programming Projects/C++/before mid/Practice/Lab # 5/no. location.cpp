#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
	int n,x,mat[4]={1,2,3,4};
	do{
		cin>>n;
		if(n=mat[x])
		cout<<x-1<<endl;
		else
		cout<<"No. is not exist in array"<<endl;
	}while(cin.get()=='Y');
	
}

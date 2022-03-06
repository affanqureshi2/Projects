#include <iostream>
using namespace std;
int main()
{
	int char_Ch[15];
	string char_Name[15];
	for (int x=0;x<15;x++)
	{
	
	cout<<"Enter the name of subject \n";
	cin>>char_Name[x];
	cout<<"Enter the Credit Hour of Subject \n";
	cin>>char_Ch[x];
}
	for(int x=0;x<15;x++)
	{
		cout<<char_Name[x]<<"="<<char_Ch[x]<<endl;
	}
	return 0;
}

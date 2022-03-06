#include <iostream>
using namespace std;
int main()
{
	int values[20],countev,countod;
	countev = 0;
	countod = 0;
	for(int x=0;x<=19;x++)
	{
		cin>>values[x];
		if (values[x]%2==0)
		countev++;
		else
		countod++;
	}
	cout<<"Even no. = "<<countev<<endl;
	cout<<"Odd no. = "<<countod<<endl;
	
	return 0;
}

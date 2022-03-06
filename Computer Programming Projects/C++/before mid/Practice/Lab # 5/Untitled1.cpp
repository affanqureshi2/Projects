#include <iostream>
using namespace std;
int main()
{
	char name[5]={'A','f','f','a','n'};
	char behold[5];
	for (int x=0;x<=4;x++)
	{
		behold[x]=name[x];
	}
	int x = 0;
	for (int x=0;x<=4;x++)
	{
		cout<<behold[x];
	}
	return 0;
}

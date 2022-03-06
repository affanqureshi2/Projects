#include <iostream>
using namespace std;
int main()
{
	int course_Ch[15];
	string course_Name[15];
	for (int x=0;x<15;x++)
	{
		cout<<"Enter the name of course = ";
		cin>>course_Name[x];
		cout<<"Enter its Credit Hour";
		cin>>course_Ch[x];
	}
	
	
	return 0;
}

#include <iostream>
using namespace std;
struct student
	{
		int roll_no;
		string name;
		float GPA;
	};
int main()
{
	student cp[3];
	int x=0;
	for (x=0;x<=2;x++)
	{
	cin>>cp[x].roll_no;
	cin>>cp[x].name;
	cin>>cp[x].GPA;
	}
	return 0;
	
}

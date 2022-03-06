#include <iostream>
using namespace std;
struct result
	{
		int roll_number;
		float GPA;
		int semester;
		char grade;
	};
int main()
{
	result Affan;
	cout<<"Enter the Roll No. of Affan # ";
	cin>>Affan.roll_number;
	cout<<"Enter the GPA of Affan # ";
	cin>>Affan.GPA;
	cout<<"Enter the Semester # ";
	cin>>Affan.semester;
	cout<<"Enter grade of Affan # ";
	cin>>Affan.grade;
	
	return 0;
}
	


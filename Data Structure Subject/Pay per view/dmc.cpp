#include <iostream>
#include <string>
using namespace std;
struct student
	{
		string name;
		int ses;
		int roll;
		int sem;
		string sub[3];
		char grade[3];
		float mark[3];
	};
void display();
int main()
{
	student cp[2];
	for (int x=0;x<=1;x++)
	{
	cout<<"Enter name"<<endl;
	cin>>cp[x].name;
	cout<<"Enter roll"<<endl;
	cin>>cp[x].roll;
	cout<<"Enter ses"<<endl;
	cin>>cp[x].ses;	
	cout<<"Enter sem"<<endl;
	cin>>cp[x].sem;
	
}
void display();
	
}
void display()
{
	cout<<"\t\t"<<"Name = "<<student.name<<"\t\t\t\t"<<"Session = "<<student.ses;
	cout<<"\t\t"<<"Roll = "<<student.roll<<"\t\t\t\t"<<"Semester = "<<student.sem;
}

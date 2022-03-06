#include<iostream>
#include<string>
using namespace std;
string e;
class student
{
	string Name;
	int Roll;
	float Marks[];
	char Grade[];
	int Semester;
	float SGPA;
	float CGPA;


public:
void input()
{	cin>>Name;
	cin>>Roll;
	for (int x=0;x<=2;x++)
	{
	cout<<"Sub"<<x;cin>>Marks[x];
	cout<<"Grade"<<x;cin>>Grade[x]; 
}
	cin>>Semester;
	cin>>SGPA;
	cin>>CGPA;	
};
void display()
{
	cout<<Name;
	cout<<Roll;
	for (int x=0;x<=2;x++)
	{
	cout<<"Sub "<<x<<" = ";cout<<Marks[x];
	cout<<"Grade "<<x<<" = ";;cout<<Grade[x]; 
}
	cout<<Semester;
	cout<<SGPA;
	cout<<CGPA;
}
};
int main()
{
	student Affan;
	Affan.input();
	Affan.display();
}


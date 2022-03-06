#include<iostream>
#include<string>
using namespace std;
string e;
struct student
{
	string Name;
	int Roll;
	float Marks[];
	char Grade[];
	int Semester;
	float SGPA;
	float CGPA;
};
	student Affan;

void input()
{	cin>>Affan.Name;
	cin>>Affan.Roll;
	for (int x=0;x<=2;x++)
	{
	cout<<"Sub"<<x;cin>>Affan.Marks[x];
	cout<<"Grade"<<x;cin>>Affan.Grade[x]; 
}
	cin>>Affan.Semester;
	cin>>Affan.SGPA;
	cin>>Affan.CGPA;	
};
void display()
{
	cout<<Affan.Name;
	cout<<Affan.Roll;
	for (int x=0;x<=2;x++)
	{
	cout<<"Sub "<<x<<" = ";cout<<Affan.Marks[x];
	cout<<"Grade "<<x<<" = ";;cout<<Affan.Grade[x]; 
}
	cout<<Affan.Semester;
	cout<<Affan.SGPA;
	cout<<Affan.CGPA;
};
int main()
{
	input();
	display();
}


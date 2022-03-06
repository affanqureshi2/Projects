#include<iostream>
#include<string>
using namespace std;
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
int main()
{
	student Affan;
	cin>>Affan.Name;
	cin>>Affan.Roll;
	for (int x=0;x<=2;x++)
	{
	cout<<"Sub"<<x;cin>>Affan.Marks[x];
	cout<<"Grade"<<x;cin>>Affan.Grade[x]; 
}
	cin>>Affan.Semester;
	cin>>Affan.SGPA;
	cin>>Affan.CGPA;
	
}


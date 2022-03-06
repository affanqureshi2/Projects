#include<iostream>
#include<string>
#include<fstream>
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
	
	student cp15[10];
	for(int x=0;x<=9;x++)
	{cout<<"Record for student "<<x<<" = ";
	cin>>cp15[x].Name;
	cin>>cp15[x].Roll;
	for (int x=0;x<=2;x++)
	{
	cout<<"Sub"<<x;cin>>cp15[x].Marks[x];
	cout<<"Grade"<<x;cin>>cp15[x].Grade[x]; 
}
	cin>>cp15[x].Semester;
	cin>>cp15[x].SGPA;
	cin>>cp15[x].CGPA;
	ofstream fout;
	fout.open("DMC.txt");
	fout<<"Name # "<<cp15[x].Name;
	fout<<"Roll No. # "<<cp15[x].Roll;
	fout<<"Sem # "<<cp15[x].Semester;
	fout.close();
}
}


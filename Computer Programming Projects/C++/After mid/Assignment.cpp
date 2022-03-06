#include <iostream>
using namespace std;

struct student
	{
		string name;
		int reg_no;
		char Programming,CA,DLD,LADE,isl;
		student *link;
	};

int main()
{
	student *head;
	head = new student;
	student *newstud;
	newstud = new student;
	cout<<"Enter the  of Student = ";
	cin>>head->name;
	cout<<"Enter the Reg No. of Student = ";
	cin>>head->reg_no;
	cout<<"Enter the Grade of Programming = ";
	cin>>head->Programming;
	cout<<"Enter the Grade of  Circuit Analysis = ";
	cin>>head->CA;
	cout<<"Enter the Grade of Digital Logic Designs = ";
	cin>>head->DLD;
	cout<<"Enter the Grade of LADE = ";
	cin>>head->LADE;
	cout<<"Enter the Grade of Islamiat = ";
	cin>>head->isl;
	cout<<"\n\n\n";
	cout<<"Name;"<<head->name<<"\t";
	cout<<"Reg No.:"<<head->reg_no<<"\n";
	cout<<"Programming:"<<head->Programming<<"\t";
	cout<<"Circuit Analysis:"<<head->CA<<"\n";
	cout<<"DLD:"<<head->DLD<<"\t\t";
	cout<<"Linear Algebra:"<<head->LADE<<"\n";
	cout<<"Islamiat:"<<head->isl<<"\n";
	head->link = newstud;
	cout<<"\n\n\n";
	cout<<"Enter the Name of Student = ";
	cin>>newstud->name;
	cout<<"Enter the Reg No. of Student = ";
	cin>>newstud->reg_no;
	cout<<"Enter the Grade of Programming = ";
	cin>>newstud->Programming;
	cout<<"Enter the Grade of  Circuit Analysis = ";
	cin>>newstud->CA;
	cout<<"Enter the Grade of Digital Logic Designs = ";
	cin>>newstud->DLD;
	cout<<"Enter the Grade of LADE = ";
	cin>>newstud->LADE;
	cout<<"Enter the Grade of Islamiat = ";
	cin>>newstud->isl;
	cout<<"\n\n\n";
	cout<<"Name;"<<newstud->name<<"\t";
	cout<<"Reg No.:"<<newstud->reg_no<<"\n";
	cout<<"Programming:"<<newstud->Programming<<"\t";
	cout<<"Circuit Analysis:"<<newstud->CA<<"\n";
	cout<<"DLD:"<<newstud->DLD<<"\t\t";
	cout<<"Linear Algebra:"<<newstud->LADE<<"\n";
	cout<<"Islamiat:"<<newstud->isl<<"\n";
	cout<<"\n\n\n";
	NULL ;
}


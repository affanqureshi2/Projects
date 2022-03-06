#include <iostream>
#include <cstdlib>
using namespace std;

struct student
{
	string name;
	int reg_no;
	float Programming, CA, DLD, LADE, isl;
	student *link;
};

int main()
{
	for (int i=0;i<10;i++)
	{
	student *head;
	head = new student;
	
	cout << "Enter the  of Student = ";
	cin >> head->name;
	cout << "Enter the Reg No. of Student = ";
	cin >> head->reg_no;
	cout << "Enter the Grade of Programming = ";
	cin >> head->Programming;
	cout << "Enter the Grade of  Circuit Analysis = ";
	cin >> head->CA;
	cout << "Enter the Grade of Digital Logic Designs = ";
	cin >> head->DLD;
	cout << "Enter the Grade of LADE = ";
	cin >> head->LADE;
	cout << "Enter the Grade of Islamiat = ";
	cin >> head->isl;
	cout << "\n\n\n";
	cout << "Name;" << head->name << "\t";
	cout << "Reg No.:" << head->reg_no << "\n";
	cout << "Programming:" << head->Programming << "\t";
	cout << "Circuit Analysis:" << head->CA << "\n";
	cout << "DLD:" << head->DLD << "\t\t";
	cout << "Linear Algebra:" << head->LADE << "\n";
	cout << "Islamiat:" << head->isl << "\n";
	head->link = head;
	cout << "\n\n\n";
}
	

}



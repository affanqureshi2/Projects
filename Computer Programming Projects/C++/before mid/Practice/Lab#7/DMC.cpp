#include<iostream>
#include<fstream>
#include<conio.h>
#include<iomanip>
using namespace std;
int x;
class Subject{
	string subject[];
	int marks[];
	char grade[];
	public:
		void subjectInput(int i){
			cout<<"Enter name of subject "<<i+1<< " : ";
			cin>>subject[x];
			cout<<"Enter marks of subject "<<i+1<< " : ";
			cin>>marks[x];
			cout<<"Enter grade of subject "<<i+1<< " : ";
			cin>>grade[x];
		}
		void showSubject(int i){
			cout<<setw(15)<<i+1<<setw(15)<<subject[x]<<setw(15)<<marks[x]<<grade[x]<<endl;
		}
};
class Student{
	string name[2];
	int rolno[2];
	int sess[2];
	int sem[2];
	Subject subs[3];
	public:
		void input(){
			for (int x=0;x<2;x++)
			{cout<<"Enter Student name : ";
			cin>>name[x];
			cout<<"Enter Student roll_no : ";
			cin>>rolno[x];
			cout<<"Enter Student session : ";
			cin>>sess[x];
			cout<<"Enter Student semester : ";
			cin>>sem[x];
			for(int i=0;i<1;i++){
				subs[i].subjectInput(i);}
			}
		}
		int search(){
			int x,z;
	cout<<"Enter the roll number of student you want to search for: ";
	cin>>z;
	cout<<endl;
	for (x=0;x<2;x++)
	{
		if (z==rolno)
		return z;
		else
		continue;
	}
			}
		
	void display()
{
	ofstream fout;
	fout.open("modi g.txt");
	int x,y;
	char a;
	do
	{
	x=search();
	if (x==rolno)
	{
	   fout<<"Name: "<<name<<" "<<setw(10)<<"Session: "<<sess<<endl;
       fout<<"Roll No. : "<<rolno<<setw(10)<<"Semester: "<<sem<<endl;
       fout<<"\n\n\n\n";
       fout<<"Sr. No."<<setw(10)<<"Name of Subject"<<setw(15)<<"Marks"<<setw(10)<<" Grade"<<endl;
       for (y=0;y<5;y++)
       {
    	  fout<<y+1<<setw(10)<<subject[y]<<setw(15)<<marks[y]<<setw(10)<<grade[y]<<endl;
	   }
    }
    else
    fout<<"Sorry! No such roll number was found!"<<endl;
    fout<<endl<<endl<<endl;
    fout<<"Do you want to run the search again? Reply with 'y' for yes and 'n' for no. ";
    cin>>a;
    fout<<endl;
    }
    while(a=='y');
}
};


int main(){
	Student stu;
	stu.input();
	cout<<endl<<endl<<endl;
	stu.display();
	return 0;
}

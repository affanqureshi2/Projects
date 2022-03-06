#include<iostream>
#include<conio.h>
#include<iomanip>
#include<fstream>
using namespace std;
string sub_name;
	int marks;
	char grade;
class Subject{
	public:
		void subjectInput(int i){
			cout<<"Enter name of subject "<<i+1<< " : ";
			cin>>sub_name;
			cout<<"Enter marks of subject "<<i+1<< " : ";
			cin>>marks;
			cout<<"Enter grade of subject "<<i+1<< " : ";
			cin>>grade;
		}
		void showSubject(int i){
			cout<<setw(15)<<i+1<<setw(15)<<sub_name<<setw(15)<<marks<<grade<<endl;
		}
};
class Student{
	public:
	string name;
	int roll_no;
	int session;
	
	int semester;
	Subject subs[2];
		void input(){
			cout<<"Enter Student name : ";
			cin>>name;
			cout<<"Enter Student roll_no : ";
			cin>>roll_no;
			cout<<"Enter Student session : ";
			cin>>session;
			cout<<"Enter Student semester : ";
			cin>>semester;
			for(int i=0;i<=2;i++){
				subs[i].subjectInput(i);
			}
		}
		void showResult(){
			cout<<setfill(' ')<<setw(10)<<left<<"Name : "<<setw(20)<<name;
			cout<<setw(10)<<"Session : "<<setw(20)<<session<<endl;
			cout<<setw(10)<<"Roll No : "<<setw(20)<<roll_no;
			cout<<setw(10)<<"Semester : "<<setw(20)<<semester<<endl;
			cout<<endl<<endl;
			cout<<setw(15)<<"Ser No."<<setw(15)<<"Subject Name"<<setw(15)<<"Marks"<<"Grade"<<endl;
			for(int i=0;i<=2;i++){
				subs[i].showSubject(i);
			}
		void fileout()
		{
			ofstream fout;
			fout.open("Affan.txt");
			fout<<"Name = "<<name<<"\t\t\t\t";
			fout<<"Roll = "<<roll_no<<endl;
			fout<<"Semester = "<<semester<<"\t\t\t\t";
			fout<<"Session = "<<session<<endl<<endl;
			fout<<setw(15)<<"Ser No."<<setw(15)<<"Subject Name"<<setw(15)<<"Marks"<<setw(15)<<"Grade"<<endl;
			for(int i=0;i<=2;i++)
			fout<<setw(15)<<i+1<<setw(15)<<sub_name<<setw(15)<<marks<<grade<<endl;
				
			fout.close();
		}
		
		}
};

int main(){
	Student stu;
	stu.input();
	stu.showResult();
	fileout();
	return 0;
}

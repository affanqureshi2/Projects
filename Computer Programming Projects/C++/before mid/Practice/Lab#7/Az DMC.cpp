#include<iostream>
#include<conio.h>
#include<string>
#include<cstdlib>
#include<fstream>
using namespace std;
struct student
{int roll_no,marks[2];
 string grade[2];
 float SGPA,CGPA;
 string sub[2];
 string name;
}; 
student cp15[2];
int search(int a)
{for(int i=1;i<=3;i++)
 {
  if(cp15[i-1].roll_no==a)
  return i;}
  return -1;
}
void input()
{for(int a=0;a<=1;a++)
 {cout<<"enter the roll number of student "<<a+1<<" : ";
  cin>>cp15[a].roll_no;
  cout<<"enter the name of student "<<a+1<<" : ";
  cin>>cp15[a].name;
  for(int b=0;b<=1;b++)
  {cout<<"enter the name of subject "<<b+1<<" for student "<<a+1<<" : ";
   cin>>cp15[a].sub[b];
  cout<<"enter the marks of subject "<<b+1<<" for student "<<a+1<<" : ";
   cin>>cp15[a].marks[b];
   cout<<"enter the grade of subject "<<b+1<<" for student "<<a+1<<" : "; 
   cin>>cp15[a].grade[b];
  }
  cout<<"enter the SGPA of student "<<a+1<<" : ";
  cin>>cp15[a].SGPA;
  cout<<"enter the CGPA of student "<<a+1<<" : ";
  cin>>cp15[a].CGPA;} 
}
 void display(int c)
{
	ofstream fout;
	fout.open("saqib.txt");
if(c==-1)
fout<<"\n\"YOU ENTER AN INVALID ROLL NUMBER\"\n";
else
{
fout<<endl;
fout<<"******************************** UET TAXILA **********************************";
fout<<endl<<endl;
fout<<"STUDENT NAME : "<<cp15[c-1].name<<endl;
 fout<<"ROLL NUMBER : "<<cp15[c-1].roll_no<<endl<<endl;
 fout<<"Sr.no:\t\tName of subject\t\tMarks\t\tGrade";
 for(int i=0;i<=1;i++)
 {fout<<endl;
 fout<<i+1<<"\t\t"<<cp15[c-1].sub[i]<<"\t\t\t"<<cp15[c-1].marks[i]<<"\t\t"<<cp15[c-1].grade[i];}
 fout<<endl<<endl;
 fout<<"SGPA : "<<cp15[c-1].SGPA<<endl;
 fout<<"CGPA : "<<cp15[c-1].CGPA;
 fout<<"\n*******************************************************************************";
fout.close();
}
}
int main()
{input();
int y,t;
char s;
 ABC:
 cout<<"enter a roll number whose DMC you want to print: ";
 cin>>y;
 t=search(y);
 display(t);
 cout<<endl<<"are you like to print any other DMC ? enter 'y' for yes otherwise enter any key to exit: ";
 cin>>s;
 if ((s=='y')||(s=='Y'))
 goto ABC;}

#include <iostream>
#include <iomanip>
using namespace std;
int main(){
	double pf,dld,ca,T,Avg;
	cout<<"Marks of the Students"<<endl;
	cout<<"Programming Fundamental =      ";
	cin>>pf;
	cout<<"Digital Logic Designing =      ";
	cin>>dld;
	cout<<"Circuit Analysis        =      ";
	cin>>ca;
	T = pf+dld+ca;
	cout<<"Total Marks             =      "<<T<<endl;
	Avg = (pf+dld+ca)/3;
	cout<<"Average in all Subjects =      "<<Avg<<endl;
	return 0;
	
	
}

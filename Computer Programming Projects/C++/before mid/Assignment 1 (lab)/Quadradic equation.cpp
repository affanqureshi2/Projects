#include <iostream>
#include <cstdlib>
#include <math.h>
using namespace std;
int main()
{
	int a,b,c,disc,root1,root2;
	cin>>a;
	cin>>b;
	cin>>c;
	disc = b^2-4*a*c;
	if (disc>0){
	root1 = -(b+sqrt(disc))/(2*a);
	root2 = -(b-sqrt(disc))/(2*a);
	cout<<root1<<endl;
	cout<<root2<<endl;
	cout<<"roots are real and unequal"<<endl;
}
	else if (disc<0){
		root1 = -(b+sqrt(-disc))/(2*a);
		root2 = -(b-sqrt(-disc))/(2*a);
		cout<<root1<<endl;
		cout<<root2<<endl;
		cout<<"roots are imaginary"<<endl;
	}
	else{
		root1 = -b/(2*a);
		cout<<"root are real"<<endl;
		

		
	}
	
	
	
	
}


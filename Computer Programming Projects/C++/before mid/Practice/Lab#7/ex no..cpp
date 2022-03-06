#include <fstream>
#include <iostream>
using namespace std;

int main()
{string s1,s2,s3;
s1 = "af.txt";
s2 = "Hamza";
s3 = s1 + s2;
cout<<s3<<endl;
ofstream fout;
	
	fout.open(s1);
	fout<<"Name"<<endl;
	fout<<"Roll"<<endl;
	fout.close();
}

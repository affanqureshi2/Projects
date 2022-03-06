#include <iostream>
#include <fstream>
using namespace std;
struct birthday
{
	int my_db;
	int today;
};
void getb(birthday& x);
int main()
{
	birthday my;
	getb(my);
}
void getb(birthday& x)
{
	int c;
	ofstream tuot;
	cout<<"Enter your year of birth = ";
	cin>>x.my_db;
	cout<<"Enter this year = ";
	cin>>x.today;
	c = x.today - x.my_db;
	tuot.open("Le Lo Le Lo Birthday Le Lo.txt");
	tuot<<"Your year of Birth = "<<x.my_db<<endl;
	tuot<<"Date of this day = "<<x.today<<endl;
	tuot<<"And You are "<<c<<" years old.";
	tuot.close();
	cout<<c<<endl;
	
}

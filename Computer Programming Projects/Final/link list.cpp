#include<iostream>
#include<string>
using namespace std;
struct glos
{
	string items;
	int quantity;
	glos*link;
};
int main()
{
	glos*new1; 
	new1 = new glos;
	glos*new2;
	new2 = new glos;
	new1->items = "TV";
	new1->quantity = 3;
	new1->link = new2;
	new2->items = "AR";
	new2->quantity = 4;
	new2->link = NULL;
	cout<<new1->items<<endl;
}



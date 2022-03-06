#include <iostream>
using namespace std;
struct purchase
	{
		int count;
		string item;
		purchase *link;
		
	};
int main()
{
	purchase * head = new purchase[3];
	//purchase *newnode;
	//newnode = new purchase;
	head[0].item = "Air Conditioner";
	head[0].count = 20;
	head[0].link = head[1];
	
	//newnode->count = 15;
	//newnode->item = "Fan";
	//newnode->link = NULL;
	cout<<head->count<<endl;
	cout<<head->item<<endl;
	//cout<<newnode->count<<endl;
	//cout<<newnode->item<<endl;
}

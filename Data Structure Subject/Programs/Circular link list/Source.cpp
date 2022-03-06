#include<iostream>
#include<string>
using namespace std;
struct terrain
{
	int name;
	terrain*link;
};
terrain*head = NULL;
terrain*ptr;
terrain*temp;
void inject(int item)
{
	ptr = new terrain;
	ptr->name = item;
	if (head == NULL)
	{
		head = ptr;
		ptr->link = head;
		temp = head;
	}
	else
	{
		while (temp->link != head)
			temp = temp->link;
		ptr->link = head;
		temp->link = ptr;
	}
}
void trav(terrain*start,int clk)
{
	terrain*tp = start;
	for (int i = 0; i < clk; i++)
	{
		do{
			cout << tp->name << endl;
			tp = tp->link;
		} while (tp != head);
	}
}
int main()
{
	int clock;
	for (int i = 0; i < 5; i++)
	{
		int a;
		cin >> a;
		inject(a);
	}
	cout << "please enter the no. of repeatition of clock" << endl;
	cin >> clock;
	trav(head,clock);
	system("pause");
	return 0;
}
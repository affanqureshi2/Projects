#include<iostream>
using namespace std;
struct ssj
{
	int data;
	ssj *link;
};
ssj *head = NULL;
ssj *ptr;
ssj *temp = NULL;
void apprend(int item)
{
	ptr = new ssj;
	ptr->data = item;
	if (head == NULL)
	{
		head = ptr;
		ptr->link = NULL;
		temp = head;
	}
	else
	{
		while (temp->link != NULL)
		{
			temp = temp->link;
		}
		temp->link = ptr;
		ptr->link = NULL;
	}
}
void traverse()
{
	ssj *trav = head;
	while (trav != NULL)
	{
		cout << trav->data << endl;
		trav = trav->link;
	}
}
int main()
{
	int a;
	for (int i = 0; i < 5; i++)
	{
		cin >> a;
		apprend(a);
	}
	traverse();
	system("pause");
}
#include<iostream>
#include<cstdlib>
#include<stdlib.h>
#include<time.h>
#include<string>
#include<iomanip>

using namespace std;
struct node
{
	int name;
	node*link;
};
void insertion(node*sample, int a);
void trav(node*sm);
int main()
{
	srand(time(NULL));
	node*head = NULL;
	node*temp = NULL;
	node*newnd;

	for (int j = 0; j < 10; j++)
	{
		newnd = new node;
		if (head == NULL)
		{
			head = newnd;
			newnd->link = NULL;
			temp = head;
		}
		else
		{
			while (temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = newnd;
			newnd->link = NULL;
		}
		newnd->name = rand() % 10;
	}
	trav(head);
	int a;
	cin >> a;
	insertion(head, a);
//	trav(head);
	system("pause");
	return 0;
}
void insertion(node*sample, int a)
{
	node *trav = sample;
	int c = 0;
	while (trav->link = NULL)
	{
		trav = trav->link;
		c++;
		if (c == a)
		{
			break;
		}
	}
	node *ptr = new node;
	node *con;
	con = trav->link;
	trav->link = ptr;
	cin >> trav->name;
}
void trav(node*sm)
{
	node*trv = sm;
	while (trv != NULL)
	{
		cout << trv->name << endl;
		trv = trv->link;
	}
}

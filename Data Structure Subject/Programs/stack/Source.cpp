#include<iostream>
#include<cstdlib>
#include<time.h>
using namespace std;
struct node
{
	int name;
	node*link;
};
void push(node*sample, int a);
void pop(node*sample);
void trave(node*sm);
int main()
{
	srand(time(NULL));
	node*head = NULL;
	node*temp = NULL;
	node*newnd;
	cout << "List is given below" << endl;
	for (int j = 0; j < 10; j++)
	{
		newnd = new node;
		newnd->name = rand() % 10;
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

	}
ab:
	{
		cout << "press 1 for push" << endl;
		cout << "press 2 for pop" << endl;
		cout << "press 3 for show the list" << endl;
		cout << "press 4 for exit" << endl;
		int rf;
		cin >> rf;
		node*newnode = new node;
		switch (rf)
		{
		case 1:
			int k;
			cin >> k;
			newnode->name = k;
			newnode->link = head;
			head = newnode;
			goto ab;
			break;
		case 2:
			head = head->link;
			goto ab;
			break;
		case 3:
			trave(head);
			goto ab;
			break;
		case 4:
			exit;
			break;
		default:
			cout << "Enter the correct key" << endl;
			goto ab;
		}
	}
}
void push(node*sample, int a)
{
	node*newnode = new node;
	newnode->name = a;
	newnode->link = sample;
	sample = newnode;
}
void pop(node*sample)
{
	node*loc = sample;
	sample = sample->link;
	delete loc;
}
void trave(node*sm)
{
	node*trv = sm;
	while (trv != NULL)
	{
		cout << trv->name << endl;
		trv = trv->link;
	}
}
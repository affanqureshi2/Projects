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
void deletion(node*sm, int a);
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
	trave(head);
	cout << endl << endl;
ab:
	{
		int n;
		cout << "Press 1 for insert" << endl;
		cout << "Press 2 for deletion" << endl;
		cout << "Press 3 to show the new list" << endl;
		cout << "Press 4 for exit" << endl;
		cin >> n;
		switch (n)
		{
		case 1:
			int b;
			cout << "On which place you want to insert the no. = ";
			cin >> b;
			cout << endl << endl;
			insertion(head, b);
			cout << endl << endl;
			goto ab;
			break;
		case 2:
			int a;
			cout << "On which place you want to delete the no. = ";
			cin >> a;
			cout << endl << endl;
			deletion(head, a);
			cout << endl << endl;
			goto ab;
			break;
		case 3:
			cout << "New list is given below" << endl;
			trave(head);
			cout << endl << endl;
			goto ab;
			break;
		case 4:
			exit;
			break;
		default:
			cout << "Please press the correct key" << endl;
			cout << endl << endl;
			goto ab;
			break;
		}
	}
	system("pause");
	return 0;
}

void insertion(node*sample, int a)
{
	node *trav = sample;
	/*	if (a == 1)
	{		node *ptr = new node;
	cout<<"Please enter the no. you want to insert = ";
	cin>>ptr->name;
	ptr->link = sample;
	sample = ptr;
	}
	*/
	int c = 2;
	while (trav != NULL)
	{
		if (c == a)
		{
			node *ptr = new node;
			cout << "Please enter the no. you want to insert = ";
			cin >> ptr->name;
			node *con;
			con = trav->link;
			trav->link = ptr;
			ptr->link = con;
		}
		trav = trav->link;
		c++;
	}
}
void deletion(node*sm, int a)
{
	node *trav = sm;
	/*	if (a == 1)
	{		node *ptr = new node;
	cout<<"Please enter the no. you want to insert = ";
	cin>>ptr->name;
	ptr->link = sample;
	sample = ptr;
	}
	*/
	int c = 2;
	while (trav != NULL)
	{
		if (c == a)
		{
			node*con;
			con = trav->link;
			trav->link = con->link;
		}
		trav = trav->link;
		c++;
	}
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

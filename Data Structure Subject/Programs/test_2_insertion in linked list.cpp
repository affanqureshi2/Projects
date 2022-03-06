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
	cout<<"List is given below"<<endl;
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
	trav(head);
	cout<<endl<<endl;
	int a;
	cout<<"On which place you want to insert the no. = ";
	cin >> a;
	cout<<endl<<endl;
	insertion(head, a);
	cout<<endl<<endl;
	cout<<"New list is given below"<<endl;
	trav(head);
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
				cout<<"Please enter the no. you want to insert = ";
				cin>>ptr->name;
				node *con;
				con = trav->link;
				trav->link = ptr;
				ptr->link = con;
			}
		trav = trav->link;
		c++;
	}
	
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


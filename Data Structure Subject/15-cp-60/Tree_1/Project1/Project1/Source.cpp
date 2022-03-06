#include<iostream>
using namespace std;
struct node
{
	int num;
	node*lft;
	node*rgt;
};
void insert(int n)
{
	node*start = NULL;
	node*temp = NULL;
	node*ptr = new node;
	ptr->num = n;
	ptr->lft = NULL;
	ptr->rgt = NULL;
	if (start == NULL)
	{
		start = ptr;
		temp = ptr;
	}
	else
	{
		if (temp->num > ptr->num)
			temp->lft = ptr;
		else if (temp->num < ptr->num)
			temp->rgt = ptr;
		temp = ptr;
	}
}
void pre_order(node*head)
{
	node*travlf = head;
	node*travlf1;
	node*travrf = head;
	node*travrf1;
	while (travlf != NULL || travlf1 != NULL)
	{
			cout << travlf->num << endl;
			if (travlf1 != NULL)
				cout << travlf1->num << endl;
			if (travrf != travlf1)
				cout << travrf->num << endl;
			travlf = travlf->lft;
			travlf1 = travlf->rgt;
	}
}
/*void in_order(node*head)
{
	node*trav;
	trav = head;
	int n[100];
	while (trav->lft != NULL)
	{
		trav = trav->lft;
		for (int i = 0; i < 10; i++)
		{
			n[i] = trav->num;
		}

	}
}*/
int main()
{
	int k;
	cin >> k;
	for (int i = 0; i < k; k++)
	{
		int n;
		cin >> n;
		insert(n);
	}
}
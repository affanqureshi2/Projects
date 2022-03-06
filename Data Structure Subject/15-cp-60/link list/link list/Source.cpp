#include<iostream>
using namespace std;
struct node
{
	int num;
	node *next;
};
bool inE(node *head);
char menu();
void IAFE(node *&head, node *&last, int num);
void In(node *&head, node *&last, int num);
void Rm(node *&head, node *&last, int num);
void SL(node *current);

bool inEmpty(node *head)
{
	if (head == NULL)
		return true;
	else
		return false;
}
/*char menu()
{

}*/
void IAFE(node *&head, node *&last, int num)
{
	node *temp = new node;
	temp->num = num;
	temp->next = NULL;
	head = temp;
	last = temp;
}
void In(node *&head, node *&last, int num)
{
	if (inE(head))
		IAFE(head, last, num);
	else
	{
		node *temp = new node;
		temp->num = num;
		temp->next = NULL;
		last->next = temp;
		last = temp;
	}
}

int main()
{
	node *head = NULL;
	node *last = NULL;
	In(head, last, num);

}
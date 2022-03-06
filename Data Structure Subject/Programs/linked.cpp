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
int main()
{
	srand(time(NULL));
	node*head = NULL;
	node*temp = NULL;
	node*newnd;
	
	for (int j = 0; j < 10; j++)
	{
		newnd = new node;
		if(head == NULL)
		{
			head = newnd;
			newnd->link = NULL;
			temp = head;
		}
		else 
		{
			while(temp->link != NULL)
			{
				temp = temp->link;
			}
			temp->link = newnd;
			newnd->link = NULL;
		}
		newnd->name = rand() % 10; 
	}
		
	
	node*trv = head;
	while(trv!= NULL)
	{
		cout<<trv->name<<endl;
		trv = trv->link;
	}
	
	system("pause");
	return 0;
}



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
	node*head;
	head = new node;

	for (int j = 0; j < 10000; j++)
	{
		
		node*newnd;
		newnd = new node;
		head->link = newnd;
		newnd->name = rand() % 1000;
		cout << newnd->name << endl;
		newnd->link = head;
	}
	system("pause");
	return 0;
}


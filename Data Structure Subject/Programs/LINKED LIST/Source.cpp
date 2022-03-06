#include <iostream>
#include <string>
using namespace std;
struct nodles
{
	string comp;
	int price;
	nodles*chain;
};
nodles *head = NULL;
nodles *temp = NULL;
nodles *ptr;
void app(string item,int pr)
{
	
	ptr = new nodles();
	ptr->comp = item;
	ptr->price = pr;
	if (head == NULL)
	{
		head = ptr;
		ptr->chain = NULL;
		temp = head;
	}
	else{
		while (temp->chain != NULL)
		{
			temp = temp->chain;
		}
		temp->chain = ptr;
		ptr->chain = NULL;
	}
}
void tran()
{
	cout << endl << endl << "\t----------*----------*----------"<<endl;
	nodles *trav = head;
	while (trav->chain != NULL)
	{
	
		cout << "Name of nodles = ";
		cout << trav->comp << endl<<endl;
		cout << "Price of nodles = ";
		cout << trav->price << endl<<endl;
		trav = trav->chain;
	}
}
int main()
{
	string a;
	int b,c;
	cout << "How many nodles data you want to enter = ";
	cin >> c;
	for (int i = 0; i < c; i++)
	{
		cout << "Enter the name of nodles = ";
		cin >> a;
		cout << "Enter the price of nodles = ";
		cin >> b;
		app(a, b);
	}
	tran();

	system ("pause");
}
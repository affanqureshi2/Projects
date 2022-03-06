#include<iostream>
#include<cstdlib>
#include<string>

using namespace std;

class node
{
public:

	string name;
	string person;
	node * linker;

	node * head;


	void function1()
	{
		node * one;
		node * two;
		one = new node;
		two = new node;

		head = one;

		cout << "Enter the name of the person: ";
		cin >> one->name;

		cout << "Enter the character of the person: ";
		cin >> one->person;

		one->linker = two;

		cout << "Enter the name of the person: ";
		cin >> two->name;

		cout << "Enter the character of the person: ";
		cin >> two->person;

		two->linker = NULL;
	}
	void function2()
	{
		node * next;
		next = head;

		while (next != NULL)
		{
			cout << "Name: ";
			cout << next->name << endl;

			cout << "Character: ";
			cout << next->person << endl;
			next = next->linker;
		}
		cout << "End of program." << endl;
	}
};
int main()
{
	node instance;
	instance.function1();
	instance.function2();
	system("PAUSE");
	return 0;
}
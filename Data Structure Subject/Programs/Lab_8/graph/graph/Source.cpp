#include <iostream>
#include <string>
#include<time.h>
using namespace std;


string InsertLine(int index)
{
	//cout << "Enter the " << index + 1 << " items size in the bar graph: ";
	int itemSize = rand()%20;

	string myString(itemSize, '*');

	return myString;

}

int main()
{
	srand(time(NULL));
	cout << "How big would you like your bar graph: ";
	int graphSize;
	cin >> graphSize;

	string *graph = new string[graphSize];

	for(int i = 0; i < graphSize; i++)
	{
		graph[i] = InsertLine(i);
	}

	cout << "---------------------------------------------------" << endl;

	for(int i = 0; i < graphSize; i++)
	{
		cout << i+1 << ": " << graph[i] << std::endl;
	}

	cout << "--------------------------------------------------" << endl;
	system("pause");
	delete[] graph;
	system("pause");
	return 0;
}
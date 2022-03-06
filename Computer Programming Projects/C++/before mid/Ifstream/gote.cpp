#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	string output;
	ifstream fin;
	fin.open("gate.txt");
	while (!fin.eof())
	{
	fin>>output;
	cout<<output;
}
	fin.close();
	
}

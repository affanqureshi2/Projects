#include <iostream>
#include <fstream>
using namespace std;
int main()
{
	ofstream hit;
	hit.open("light.txt");
	hit<<"Tahir shah";
	hit.close();
}

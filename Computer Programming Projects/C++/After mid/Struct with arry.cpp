#include <iostream>
#include <string>
int main()
{
using namespace std;
struct CandyBar
{
	std::string name;
	float weight;
	int calories;
};
	
CandyBar * pointer = new CandyBar[3];
cout << "Enter the nameof snack: ";

for (int i=0;i<3;i++)
{
getline(cin, pointer[i].name);
cout << pointer[i].name<<endl;
}
system("pause");
return 0;
}

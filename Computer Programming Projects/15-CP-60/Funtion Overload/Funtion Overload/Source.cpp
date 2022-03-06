#include<iostream>
#include<string>
using namespace std;
/*int max(int a, int b)
{
	if (a > b)
		return a;
	else
		return b;
}
float max(float a, float b)
{
	if (a > b)
		return a;
	else
		return b;
}
string max(string a, string b)
{
	if (a > b)
		return a;
	else
		return b;
}*/
template <typename Y>
Y max(Y &a, Y &b)
	{
		if (a > b)
		return a;
		else
			return b;
	}
int main()
{
	int a = 10;
	int b= 20;
	cout << max(a, b)<<endl;

	float f1 = 187;
	float f2 = 100.75;
	cout << max(f1, f2) << endl;

	string fruit1 = "Orange";
	string fruit2 = "Mango";
	cout << max(fruit1, fruit2) << endl;

	system("pause");
}
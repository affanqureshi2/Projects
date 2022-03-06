#include<iostream>
using namespace std;
class rectangle
{
public:
	int length;
	int width;


	int perimeter()
	{
		return (length + width);
	}
	int area()
	{
		return length*width;
	}
	rectangle operator *(const rectangle& b)
	{
		rectangle rect;
		rect.length = this->length * b.length;
		rect.width = this->width * b.width;
		return rect;
	}
};
int main()
{
	rectangle rec1, rec2, rec3;
	cout << "Enter the length of rec1" << endl;
	cin >> rec1.length;
	cout << "Enter the lenth of rec2" << endl;
	cin >> rec2.length;
	cout << "Enter the width of rec1" << endl;
	cin >> rec1.width;
	cout << "Enter the width of rec2" << endl;
	cin >> rec2.width;
	rec3 = rec1 * rec2;
	cout << rec3.area() << endl;
	system("pause");
}
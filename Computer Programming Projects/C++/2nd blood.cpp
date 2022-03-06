#include <iostream>
using namespace std;

class Area
{

	int length, width;
	public:
	void rea()
	{
	
		cin>>length;
		cin>>width;
		int ar;
		ar = length * width;
		cout<<ar;
	}
};
int main()
{
	Area pipe;
	pipe.rea();
	
}

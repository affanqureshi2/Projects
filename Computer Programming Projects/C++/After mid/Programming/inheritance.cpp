#include <iostream>
#include <iomanip>
using namespace std;
class shape
{
	public:
		void setwidth(int w) 
		{width = w;};
		void setheight(int h)
		{height = h;};
	protected:
		int width;
		int height;
};
class rectangle : public shape
{	public:
	int getarea()
	{
		return(width*height);
	}
};
int main()
{
	rectangle set;
	set.setwidth(10);
	set.setheight(15);
	cout<<set.getarea();
	return 0;
}

#include <iostream>
using namespace std;
int main()
{
	int a,b;
	cin>>a;
	b=2;
	if(b<a){
	
	
	while(b<a)
	{
		if(a%b==0)
		{
		cout<<"This is not a prime no."<<endl;
		break;
		
		}
		else if(a%b!=0) {
		if (b==a-1)
		{
		cout<<"This is prime no."<<endl;
		
		break;
		
		}}
		b++;
		
}
}
}
	
	



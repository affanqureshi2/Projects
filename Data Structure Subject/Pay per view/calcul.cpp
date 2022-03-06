#include <iostream>
using namespace std;
void cal(int,char,int);
int main()
{
	cal(3,'+',4);
	return 0;
}
void cal(int a,char op,int b)
{
	float result;
	cout<<"Enter the first integer\n";
		cin>>a;
		cout<<"Enter the second integer \n";
		cin>>b;
		cout<<"Enter the operator \n";
		cin>>op;
		switch(op)
		{
			case '+':
				{result = a+b;
				cout<<"Sum is "<<result<<endl;
				break;
				}
			case '-':
				{result = a-b;
				cout<<"Sub is "<<result<<endl;
				break;
				
				}
			case '*':
				{result = a*b;
				cout<<"Mul is "<<result<<endl;
				break;
				}
		
			case '/':
		{
			result=a/b;
			cout<<"Division is "<<result<<endl;
			break;
		}
			case '%':
		{
			result=a%b;
			cout<<"Remainder is "<<result<<endl;
			break;
		}
		
}
}

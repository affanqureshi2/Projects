#include<iostream>
#include<cstdlib>
#include<string>
using namespace std;
int top = -1;
int A[10];
int push(int x)
{
	if (top == 9)
		{
			cout << "Error:stack overflow";
			
		}
	top = top + 1;
	cout << top<<":";
	A[top] = x;
	 
	return A[top];
}
int pop()
{
	top = top - 1;
	return A[top];

}
int Top()
{
	return A[top];

}

int main()
{

	 cout<<push(1)<<endl;
	 cout << push(2)<<endl;
	 cout << push(3)<<endl;
	 cout << pop()<<endl;
	 cout << push(5) << endl;
	 for (int i = 0; i < 5; i++)
	 {
		 cout << A[i]<<endl;
	 }
	 system("pause");

	return 0;
}
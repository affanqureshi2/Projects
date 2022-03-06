#include<iostream>
using namespace std;
struct prime
{
	int num;
	prime*node;
};
int main()
{
	prime*j7;
	j7 = new prime;
	prime*j5;
	j5 = new prime;
	cin>>j7->num;
	j7->node = j5;
	cin>>j5->num;
	j5->node = NULL;
	prime*temp;
	temp = new prime;
	temp->node = j5;
	cout<<temp->num<<endl; 
	
}

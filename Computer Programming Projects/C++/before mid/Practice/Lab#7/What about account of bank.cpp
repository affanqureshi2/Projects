#include <iostream>
using namespace std;
struct account
	{
		double interest_rate;
		double balance;
		int term;
	};
void getinfo(account& x);
int main()
{
	double interest,rate_faction;
	account cd;
	getinfo(cd);
	rate_faction = cd.interest_rate/100;
	interest = cd.balance*rate_faction*cd.term/12;
	cd.balance = cd.balance + interest;
	cout<<"Balance after interest = ";
	cout<<cd.balance;
}
void getinfo(account& x)
{
	cout<<"Enter the Balance = $";
	cin>>x.balance;
	cout<<"Enter the interest rate = ";
	cin>>x.interest_rate;
	cout<<"Enter the Time in terms of month = $";
	cin>>x.term;
}

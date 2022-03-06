#include<iostream>
using namespace std;

int main(){

int a = 0;
int k;
// the loop function runs over and over again forever
 // if(a == 16)
  //  a=0;
  bool x = 0;
  
  while(a<16){
  
  x=a%2;
  k = a/2;
  cout<<x;
  x = k%2;
  k = k/2;
  cout<<x;
  x = k%2;
  k = k/2;
  cout<<x;
  x= k%2;
  k = k/2;
  cout<<x<<endl;
  a++;  
}
}

#include<iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter a number to check if it is even or odd: ";
  cin >> num;

  if(num%2 == 0){
    cout<<num<< " is even\n";
  }else{
    cout<<num<< " is odd\n";  
  }
  return 0;
}
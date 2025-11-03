// Question 2 : WAP to print the multiplication table of a number, entered by the user.
#include <iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter the number:\n";
  cin>>num;
  for (int i = 0; i<=10; i++){
    cout<<num<<" X "<< i << " = "<<num*i<<endl;
  }
  cout<<"Table printed";
  return 0;
}

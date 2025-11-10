// Qs. WAF to print if a number is odd or even.

#include <iostream>
using namespace std;

bool isEven(int num){
  return num%2==0;
}
int main(){
  if (isEven(34)){
    cout<<"even";
  }
  else{
    cout<<"odd";
  }
  return 0;
}
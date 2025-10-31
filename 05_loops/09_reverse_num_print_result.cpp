// Reverse a given number and print the result

#include <iostream>
using namespace std;

int main(){
  int num = 123456;
  int result = 0;
  while(num>0){
    result = result*10 + num%10;
    num/=10;
  }
  cout<<result;
  return 0;
}
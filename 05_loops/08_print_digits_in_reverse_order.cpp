// Print the digits of a number in reverse order using while loop

#include <iostream>
using namespace std;

int main(){
  int num = 1236789;
  while (num>0){
    cout<<num%10;
    num/=10;
  }
  return 0;
}
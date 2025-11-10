// Qs. WAF to print the factorial of a number, n.
#include <iostream>
using namespace std;

int facto(int num){
  int fact = 1;
  for(int i = 1; i<=num; i++){
    fact*= i;
  }
  return fact;
}

int main(){
  cout<<facto(5);
  return 0;
}
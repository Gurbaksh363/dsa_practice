// Qs. WAP to print if a number is prime or not.

#include <iostream>
using namespace std;

bool isPrime(int num){
  if (num==1){
    return false;
  }
  for (int i = 2; i<num; i++){
    if (num%i==0){
      return false;
    }
  }
  return true;
}

bool isPrime2(int num){
  if (num==1){
    return false;
  }
  for (int i = 2; i*i<=num; i++){
    if (num%i==0){
      return false;
    }
  }
  return true;
}
int main(){
  cout<< isPrime2(3);
  return 0;
}
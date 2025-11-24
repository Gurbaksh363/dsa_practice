// Question 2: Write a function to calculate the sum of digits of a number.
#include <iostream>
using namespace std;

int sumOfDigits(int num){
  int sum = 0;

  while(num>0){
    sum+= num%10;
    num/=10;
  }
  
  return sum;
}
int main(){
  cout<< sumOfDigits(450921);
  return 0;
}
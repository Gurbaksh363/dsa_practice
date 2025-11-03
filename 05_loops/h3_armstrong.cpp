// Question 3 : WAP to input a number and check whether the number is an Armstrong
// number or not.

// An Armstrong number is a number that is equal to the sum of cubes of its digits.

#include <iostream>
using namespace std;

int main(){
  int num; 
  cout<<"Enter the num:\n";
  cin>>num;

  // Copy num
  int numCopy = num, sum=0;
  int lastDig;
  
  // Calculate sum of cubes of digits
  for (; num>0; num/=10){
    lastDig = num%10;
    sum += lastDig*lastDig*lastDig;
  }
  
  // Check sum is equal to orignal number
  if (numCopy==sum){
    cout<<"Yes, it is armstrong\n";
  }else{
    cout<<"No, it is not armstrong\n";
  }
  return 0;
}
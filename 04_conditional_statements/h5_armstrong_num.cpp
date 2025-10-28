// Question 5: For any 3 digit number check whether it's an Armstrong number or not.
// Armstrong number is a number that is equal to the sum of cubes of its digits.
// Eg: 371 is an armstrong number.
// 3*3*3 + 7*7*7 + 1*1*1 = 371
// Bonus: Read up about the difference between typedef (keyword), macros & const
// (keyword) in C++.

#include<iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter the num to check if it's armstrong: \n";
  cin>> num;
  int totalSum = 0, lastDigit, originalNumber= num;
  
  while(num!=0){
    lastDigit = num%10;
    totalSum+= lastDigit*lastDigit*lastDigit;
    num/=10;
  }

  if (totalSum== originalNumber){
    cout<<"Yes, armstrong number\n";
  }
  else{
    cout<<"No, not a armstrong number\n";
  }

  return 0;
}
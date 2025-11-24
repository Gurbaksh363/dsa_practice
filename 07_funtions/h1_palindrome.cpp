// Question 1: Write a function to check if a number is a palindrome in C++.
// (121 is a palindrome, 321 is not)
// APNA
// A number is called a palindrome if the number is equal to the reverse of a number.
// COLLEGE
// Eg: 121 is a palindrome because the reverse of 121 is 121 itself. On the other hand,
// 321 is not a palindrome because the reverse of 321 is 123, which is not equal to 321.
#include <iostream>
using namespace std;

int reverse(int num){
  int rev = 0;

  while (num > 0){
    rev = rev*10 + num%10;
    num/=10;
  }

  return rev;
}

bool isPalindrome(int num){
    int revNum = reverse(num);
    return num == revNum;
}

int main(){
  cout<< isPalindrome(121)<<endl;
  cout<< isPalindrome(1224)<<endl;
  return 0;
}
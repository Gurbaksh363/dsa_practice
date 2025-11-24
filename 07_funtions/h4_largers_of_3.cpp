// Question 4: Write a function that prints the largest of 3 numbers.
#include <iostream>
using namespace std;

int largestOfThree(int a, int b, int c){
  if (a >= b && a >= c){
    return a;
  }else if(b >= c){
    return b;
  }
  return c;
}

int main(){
  cout<< largestOfThree(45, 123, 11);
  return 0;
}
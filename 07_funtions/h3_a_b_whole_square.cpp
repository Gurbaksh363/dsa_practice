// Question 3: Write a function which takes 2 numbers as parameters (a & b) and
// outputs : a^2 + b^2 + 2*ab.

#include <iostream>
using namespace std;

int abWholeSqaure(int a, int b){
  return (a*a) + (b*b) + (2*a*b);
}
int main(){
  cout<< abWholeSqaure(3, 6);
  return 0;
}
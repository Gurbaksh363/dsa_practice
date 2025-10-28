// Question 1: In a program, input the side of a square. You have to output the area of
// the square.
// Input : n (side)
// Output: n*n (area)

#include <iostream>
using namespace std;

int main(){
  int side;
  cout<<"Enter length of the side: ";
  cin>> side;
  int area = side*side;
  cout<<"Area of square is: "<< area;
  return 0;
}
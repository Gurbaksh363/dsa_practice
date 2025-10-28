// Question 4: Write a program to calculate the area of a circle.
// Input : r (radius)
// Output: PI*r*r (area)

#include<iostream>
using namespace std;

#define PI 3.14

int main(){
  float rad;
  cout<<"Enter radius of circle: ";
  cin>> rad;
  
  float area= PI * rad * rad;
  cout<<"Area of circle is "<<area;
}
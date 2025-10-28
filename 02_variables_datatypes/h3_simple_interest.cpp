// Question 3: Build a Simple Interest Calculator.
// Input : principal (P), rate (R), time (T)
// Output : (P*R*T) / 100
#include <iostream>
using namespace std;

int main(){
  float p, r, t;
  cout<<"Enter principal, rate and time for simple interest (press enter after entering each value): ";
  cin>> p>> r>> t;
  float simple_interest = (p*r*t)/100;
  cout<<"Simple interest is: "<< simple_interest;
}

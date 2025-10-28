// Create an Income Tax Calculator.
// income < 5L
// 0% tax
// income between 5-10L
// 20% tax
// income > 10L
// 30% tax

#include<iostream>
using namespace std;

int main(){
  float income, tax;
  cout<<"Enter your income: "<<endl;
  cin>> income;
  if (income < 500000){
    tax = 0;
  }else if(income < 1000000){
    tax = 20/100 * income ;
  }else{
    tax = 30/100 * income;
  }

  cout<<"Tax to pay is: "<<tax;
  return 0;
}

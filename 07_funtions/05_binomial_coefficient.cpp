// Binomial Coefficient => nCr = n!/(r! * (n-r)!)
#include <iostream>
using namespace std;

int factorial(int num){
  int fact = 1;
  for(int i = 1; i<=num; i++){
    fact = fact * i;
  }
  return fact;
}

int bioCoeff(int n, int r){
  int val1 = factorial(n);
  int val2 = factorial(r);
  int val3 = factorial(n-r);

  int result = val1 / (val2 * val3);
  
  return result;
}

int main(){
  cout<<bioCoeff(4, 2)<<"\n";
  cout<<bioCoeff(3, 2);  
  return 0;
}
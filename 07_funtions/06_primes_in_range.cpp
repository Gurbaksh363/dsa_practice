#include <iostream>
using namespace std;

bool isPrime(int num){
  if (num == 1){
    return false;
  }
  for (int i = 2;  i*i<=num; i++){
    if(num % i == 0){
      return false;
    }
  }
  return true;
}

void printPrimesUptoN(int n){
  for(int i = 2; i<=n; i++){
    if (isPrime(i)){
      cout<<i<<" ";
    }
  }
}

int main(){
  printPrimesUptoN(20);
  return 0;
}
#include <iostream>
using namespace std;

void deciToBin(int deciNum){
  int n = deciNum;
  int binNum=0;
  int pow = 1; // 10^0 =1
  while(n>0){
    int rem = n%2;
    binNum = binNum + rem*pow;
    pow = pow*10;
    n=n/2;
  }
  cout<<binNum;
}

int main(){
  deciToBin(9);
  return 0;
}
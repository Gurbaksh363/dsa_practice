#include <iostream>
using namespace std;

int main(){
  int num = 1123456;
  int sum = 0;
  while(num>0){
    int digit = num%10;
    if (digit%2!=0){
      sum+=digit;
    }
    num/=10;
  }
  cout<<"Sum is: "<<sum;
  return 0;
}
// Print sum of digits of a number using while loop

#include <iostream>
using namespace std;

int main(){
  int num = 6712345;
  int sum = 0;
  while(num>0){
    sum += num%10;
    num/=10;
  }
  cout<<"Sum is: "<<sum<<endl;
  return 0;
}
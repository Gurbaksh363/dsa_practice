// Question 1: Print the 0-1 Triangle Pattern.
// For n = 5
// 1
// 01
// 101
// 0101
// 10101

#include <iostream>
using namespace std;

int main(){
  int n = 5;
  int num;
  for(int i = 1; i<=n; i++){
    i%2==0 ? num=0: num=1;
    for(int j=1; j<=i; j++){
      cout<<num;
      num==1? num=0: num=1;
    }
    cout<<endl;
  }
  return 0;
}
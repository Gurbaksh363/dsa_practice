#include <iostream>
using namespace std;
// 0, 1, 1, 2, 3, 5, 8, 13 21
// 0  1  2  3  4  5  6   7  8
int fibonacci(int n){
  if (n==0 || n==1){
    return n;
  }
  return fibonacci(n-1) + fibonacci(n-2);
}
int main(){
  cout<< fibonacci(0)<<endl;
  cout<< fibonacci(1)<<endl;
  cout<< fibonacci(2)<<endl;
  cout<< fibonacci(3)<<endl;
  cout<< fibonacci(4)<<endl;
  cout<< fibonacci(5)<<endl;
  cout<< fibonacci(6)<<endl;
  cout<< fibonacci(7)<<endl;
  cout<< fibonacci(8);
  return 0;
}
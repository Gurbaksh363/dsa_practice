// Question 3: Print the Palindromic Pattern with Numbers.
// For n = 5
//     1
//    212
//   32123
//  4321234
// 543212345
#include <iostream>
using namespace std;

int main(){
  int n=5;
  int num;
  for (int i = 1; i<=n; i++){
    for (int j = 1; j<= n-i; j++){
      cout<<" ";
    }
    num=i;
    bool dec = true;
    for(int j = 1; j<=2*i-1; j++){
      cout<<num;
      if (num==1) dec=false;
      dec ? num--:num++;
    }
    cout<<endl;
  }
  return 0;
}
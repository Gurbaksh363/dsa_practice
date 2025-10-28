// Print largest of 3 number
#include<iostream>
using namespace std;

int main(){
  int a, b, c;
  cout<<"Enter three numbers separated by space: "<<endl;
  cin>> a >> b >> c;

  // if (a>b){
  //   if (a>c){
  //     cout<<a;
  //   }
  //   else{
  //     cout<<c;
  //   }
  // }else{
  //   if (b>c){
  //     cout<<b;
  //   }else{
  //     cout<<c;
  //   }
  // }
  if (a>= b && a>=c){
    cout<<a; // a is largest
  }else if (b>=c){
    cout<<b;
  }else{
    cout<<c;
  }
  return 0;
}
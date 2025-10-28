// Question 1: Write a C++ program to get a number from the user and print whether
// it's positive, negative or zero.

#include <iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter num: "<<endl;
  cin>>num;

  if(num>0){
    cout<<"Positive\n";
  }else if(num==0){
    cout<<"Zero\n";
  }else{
    cout<<"Negative\n";
  }
  
  return 0;
}
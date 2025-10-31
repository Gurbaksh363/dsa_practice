// Qs. WAP to show numbers entered by user except multiples of 10

#include <iostream>
using namespace std;

int main(){
  int num;
  do{
    cout<<"Enter num: \n";
    cin>>num;
    if (num%10==0){
      continue;
    }
    cout<<"The number entered: "<<num<<endl;
  }while(true);
  cout<< "Program has ended.\n";
  return 0;
} 
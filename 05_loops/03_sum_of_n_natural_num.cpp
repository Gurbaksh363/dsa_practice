#include<iostream>
using namespace std;

int main(){
  int n, sum = 0;
  cout<<"Enter a num:\n";
  cin>>n;

  for (int i=0; i<n; i++){
    sum+=i+1;
  }
  cout<<"Sum is: "<< sum;
  return 0;
}
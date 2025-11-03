// Question 4: For a positive N, WAP that prints all the prime numbers from 2 to N.
// (Assume N >= 2)
#include <iostream>
using namespace std;

int main(){
  int num;
  cout<<"Enter the num\n";
  cin>>num;
  bool isPrime;

  // Check num for 2 to N
  for(int i = 2; i<= num; i++){
    isPrime = true;
    // Check if i is Prime
    for (int j = 2; j<i; j++){
      if (i%j==0){
        isPrime=false;
        break;
      }
    }
    // Print i if prime
    if (isPrime){cout<<i<<" ";}
  }
  return 0;
}
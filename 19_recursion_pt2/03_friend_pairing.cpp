// find total ways in which n friends can be paired up.
// Each friend can only be paired once.
#include <iostream>
using namespace std;

int friendsPairing(int n){
  if (n==1|| n==2){
    return n;
  }
  // for 1 person:  single + choices * pairing
  return friendsPairing(n-1) + (n-1) * friendsPairing(n-2);
}
int main(){
  cout<<friendsPairing(4);
  return 0;
}
#include <iostream>
using namespace std;

// TC: O(log n)
int xPowerN(int x, int n){
  if (n==0){
    return 1;
  }
  int halfPower = xPowerN(x, n/2);
  int halfPowerSq = halfPower* halfPower;

  if (n%2!=0) return x * halfPowerSq;
  return halfPowerSq;
}
// 2^10 = 2^5 * 2^5
// 2^5 =  2 * 2^2 * 2^2
// 2^2 = 2^1 * 2^1
// 2^1 = 2 * 2^0 * 2^0
// power 0 = 1
// power even : halfPow  * halfPow
// power odd : x 8 halfPow * halfPow
int main(){
  cout<<xPowerN(2, 5)<<endl;
  cout<<xPowerN(4, 5)<<endl;
  return 0;
}
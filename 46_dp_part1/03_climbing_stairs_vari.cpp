// count ways to reach nth stiar with 1 or 2  or 3 jumps at a time
#include <iostream>
#include <vector>
using namespace std;


int climbingStairsTab(int n){
  vector<int> dp(n+1, -1);
  dp[0] = 1;
  dp[1] = 1;
  dp[2] = 2;
  for (int i = 3; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2] + dp[i-3];
  }
  return dp[n];
}


int main(){
  int n= 4;
  cout<<climbingStairsTab(n);
  return 0;
}
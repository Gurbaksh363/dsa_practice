// count ways to reach nth stiar with 1 or 2 jumps at a time
#include <iostream>
#include <vector>
using namespace std;

int climbingStairs(int n){
  if (n==0||n==1){  // for n=0 that is also a way, where we take 0 jumps
    return 1;
  }
  return climbingStairs(n-1) + climbingStairs(n-2); // if we take 1 jump + if we take two jumps at current level or 
  // if we take 1 jump n-1 stairs are left, if we take 2 jumps n-2 stairs are left
}

int climbingStairsMemo(int n, vector<int>& memo){
  if (n==0 || n==1){
    return 1;
  }
  if (memo[n]!=-1){
    return memo[n];
  }

  return memo[n] = climbingStairsMemo(n-1, memo)+ climbingStairsMemo(n-2, memo);
}
int climbingStairsTab(int n){
  vector<int> dp(n+1, -1);
  dp[0] = 1;
  dp[1] = 1;
  for (int i = 2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}


int main(){
  int n= 5;
  vector<int>memo(n+1, -1);
  cout<<climbingStairs(n)<<endl;
  cout<<climbingStairsMemo(n, memo)<<endl;
  cout<<climbingStairsTab(n);
  return 0;
}
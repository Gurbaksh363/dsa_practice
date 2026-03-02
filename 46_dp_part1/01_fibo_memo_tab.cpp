#include <iostream>
#include <vector>
using namespace std;

int fib(int n){
  if (n==1 || n==0) return n;

  return fib(n-1)+fib(n-2);
}

int fibMemo(int n, vector<int>& memo){
  if (n==1||n==0) return n;
  
  if(memo[n]!=-1){
    return memo[n];
  }
  return memo[n] = fibMemo(n-1, memo) + fibMemo(n-2, memo);
}
int fibTab(int n){
  // Step1: define DS
  vector<int>dp(n+1, 0);
  // Step2: intialize with smallest soln
  dp[0] = 0;
  dp[1] = 1;
  // Step3: smaller->bigger soln
  for (int i = 2; i<=n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}
int main(){
  int n= 6;
  vector<int>memo(n+1, -1); // n+1 because we want to access index 6 as well
  cout<<fib(n)<<endl;
  cout<<fibMemo(n, memo)<<endl;
  cout<<fibTab(n);
  return 0;
}
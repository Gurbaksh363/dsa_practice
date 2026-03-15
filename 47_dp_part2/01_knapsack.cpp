#include <iostream>
#include <vector>
using namespace std;

int knapsackRec(vector<int>& val, vector<int>& wt, int W, int n){
  // base case: capacity = 0 || items = 0
  if (n==0|| W==0){
    return 0;
  }

  int itemWt = wt[n-1];
  int itemProfit = val[n-1];
  // include 
  int select = 0;
  if (itemWt<=W){
    select = itemProfit + knapsackRec(val, wt, W-itemWt, n-1);
  }
  // exclude
  int reject = knapsackRec(val, wt, W, n-1);

  // return max profit for this subproblem
  return max(select, reject);
}
int knapsackMemo(vector<int>& val, vector<int>& wt, int W, int n, vector<vector<int>>& memo){
  if (n==0|| W==0){
    return 0;
  }
  // checking if for current items and current capacity profit is already stored?
  if (memo[n][W]!=-1){
    return memo[n][W];
  }
  int itemWt = wt[n-1];
  int itemProfit = val[n-1];
  int select = 0;
  if (itemWt<=W){
    select = itemProfit + knapsackMemo(val, wt, W-itemWt, n-1, memo);
  }
  int reject = knapsackMemo(val, wt, W, n-1, memo);
  // updating memo with max profit
  return memo[n][W] = max(select, reject);
}

int knapsackTab(vector<int>& val, vector<int>& wt, int W, int n){
  // base case: capacity = 0 || items = 0
  if (n==0|| W==0){
    return 0;
  }
  vector<vector<int>> dp (n+1, vector<int>(W+1, 0));

  for(int i = 1; i<n+1; i++){
    for(int j = 1; j<W+1; j++){
      int itemProfit = val[i-1];
      int itemWt = wt[i-1];
      int select = 0;
      if (itemWt<=j){
        select = itemProfit + dp[i-1][j-itemWt];
      }
      int reject = dp[i-1][j];
      dp[i][j] = max(select, reject);
  
    }
  }
  return dp[n][W];
}


int main(){
  vector<int> val = {15, 14, 10, 45, 30};
  vector<int> wt = {2, 5, 1, 3, 4};
  int W = 7;
  int n = 5; // no of items

  // items and wt change in each iteration so they are used in memo
  vector<vector<int>> memo (n+1, vector<int>(W+1, -1));
  cout<<knapsackRec(val, wt, W, n)<<endl;
  cout<<knapsackMemo(val, wt, W, n, memo)<<endl;
  cout<<knapsackTab(val, wt, W, n)<<endl;
  return 0;
}
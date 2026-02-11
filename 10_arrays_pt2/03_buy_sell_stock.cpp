// Given an array where each element represents the stock price on that day,
// find the maximum profit possible by buying on one day and selling on a later day. 
// If no profit is possible, return 0.
#include <iostream>
#include <climits>
using namespace std;

// TC: O(n+n) = 2n = n, SC: O(n)
int maxProfit(int* arr, int n){
  int bestBuy[100000]; // *** WE CAN'T PASS DYNAMIC SIZE INSIDE FUNCTION
  bestBuy[0] = INT_MAX;
  for(int i = 1; i<n; i++){
    // we are finding possible min buying price for each selling day
    bestBuy[i] = min(arr[i-1], bestBuy[i-1]);
  }
  // profits...  given selling day - best buy price
  int maxProfit = 0;
  for (int i = 0; i<n; i++){
    maxProfit = max(maxProfit, arr[i]- bestBuy[i]);
  }
  return maxProfit;
}

// TC: O(N), SC: O(1) // STACK APPROACH
int maxProfit2(int* arr, int n){
  int maxProfit = 0;
  int bestBuyday = 0;
  for (int i = 1; i<n; i++){
    // max of old profit and today's profit
    maxProfit = max(maxProfit, arr[i]-arr[bestBuyday]);
    // checking if today's stock price is less so that it can be my buying day
    bestBuyday = arr[i]<arr[bestBuyday]? i : bestBuyday;
  }
  return maxProfit;

}
int main(){
  int arr[6] = {7, 1, 5, 6, 3, 4};
  // int arr[6] = {7, 6, 5, 4, 3, 2};
  int size = sizeof(arr)/sizeof(int);
  int main = 3;  // lol we can use function names as variable inside it
  // int maxProfit = 3;   // this throws error because duplicate name inside same namespace;
  // cout<<maxProfit;


  cout<<"Max profit is "<<maxProfit(arr, size)<<endl;
  cout<<"Max profit is "<<maxProfit2(arr, size)<<endl;
  return 0;
}
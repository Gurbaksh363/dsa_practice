#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int zeroSumLargestSubarray(vector<int> arr){
  unordered_map<int, int> mp; // (sum[idx], idx)
  int maxLen = 0;
  int sum = 0;
  for(int j = 0; j<arr.size(); j++){
    sum += arr[j];
    if(mp.count(sum)){
      int idx = mp[sum];
      maxLen = max(maxLen, j-idx);
    }else{
      mp[sum] = j;
    }
  }
  return maxLen;


}
int main(){
  vector<int> arr = {15, -2, 2, -8, 1, 7, 10};
  cout<<"Largest Subarray length with sum 0 is: "<< zeroSumLargestSubarray(arr);
  return 0;
}
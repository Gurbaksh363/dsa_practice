#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
// subarray count wehre sum equals  k
int kSumCountSubarray(vector<int> arr, int k){  // sum[i, j] = sum[j] - sum[i-1]
  unordered_map<int, int> mp; // (sum[idx], count)
  mp[0] =1;
  int sum = 0;
  int count = 0;
  for(int j = 0; j<arr.size(); j++){
    sum += arr[j];
    if(mp.count(sum-k)){
      count += mp[sum-k];
    }
    mp[sum]++;
  }
  return count;
}
int main(){
  vector<int> arr = {10, 2, -2, -20, 10};
  int k = -10;
  cout<<"Count of subarray where sum is k: "<<kSumCountSubarray(arr, k);
  return 0;
}
// Question 1 : Given an integer array nums, return true if any value appears at least
// twice in the array, and return false if every element is distinct. 

// Examples :
// Input: nums = [1,2,3,4]
// Output: false

// Input: nums = [1,1,1,3,3,4,3,2,4,2]
// Output: true

#include <iostream>
using namespace std;
// TC: O(n^2), SC: O(1)
bool hasDuplicate(int* nums, int n){
  for (int i = 0; i< n; i++){
    for (int j = i+1; j<n; j++){
      if (nums[i]==nums[j]){
        return true;
      }
    }
  }
  return false;
}
// BETTER APPROACH WOULD BE SORTING (N LOG N) + TWO POINTER APPROACH (N) = O(N LOG N)
int main(){
  int nums[] = {1, 2, 3, 4};
  int size = sizeof(nums)/sizeof(int);
  
  int nums2[] ={1,1,1,3,3,4,3,2,4,2};
  int size2 = sizeof(nums2)/sizeof(int);

  cout<<hasDuplicate(nums, size)<<endl;
  cout<<hasDuplicate(nums2, size2);
  return 0;
}
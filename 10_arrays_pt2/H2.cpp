// (MEDIUM)

// Question 2 : There is an integer array nums sorted in ascending order (with distinct
// values).

// Prior to being passed to your function, nums is possibly rotated at an unknown pivot
// index k (1 <= k < nums.length) such that the resulting array is [nums[k], nums[k+1], ...,
// nums[n-1], nums[0], nums[1], ..., nums[k-1]] (0-indexed). For example, [0,1,2,4,5,6,7]
// might be rotated at pivot index 3 and become [4,5,6,7,0,1,2].

// Given the array 'nums' after the possible rotation and an integer target, return the
// index of target if it is in nums, or -1 if it is not in nums.

// You must write an algorithm with O(log n) runtime complexity. [link]

// Examples :
// Input: nums = [4,5,6,7,0,1,2], target = 0
// Output: 4
// Input: nums = [4,5,6,7,0,1,2], target = 3
// Output: -1

#include <iostream>
using namespace std;

// TC: O(N) SC: O(N)
int search1(int* nums, int n, int target){
  for (int i = 0; i<n; i++){
    if (nums[i]==target){
      return i;
    }
  }
   return -1 ;
}

// TC: O(log n)
int search2(int* nums, int n, int target){
  int left = 0, right = n-1, mid;

  while (left<=right){

    mid = left + (right-left)/2;

    if (nums[mid] == target)
      return mid;

    // Find sorted half: (cuz we can easily check if target is in that half and eliminate the other part)
    // if left half is sorted
    else if (nums[left]<=nums[mid]){
      // Check if target is in sorted half 
      if (target >= nums[left] && target < nums[mid]){
        // update half
        right = mid - 1;
      }else{
        left = mid + 1;
      }
    }
  
    else{
      if (target > nums[mid] && target <= nums[right] ){
        left = mid + 1;
      }
      else {
        right = mid - 1;
      }
    }
  }
  return -1;
}
int main(){
  int nums[] = {4, 5, 6, 7, 0, 1, 2};
  int size = sizeof(nums)/sizeof(int);
  int target = 5;

  cout<<search1(nums, size, target)<<endl;
  cout<<search2(nums, size, target);

    return 0;
}

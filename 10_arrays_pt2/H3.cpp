// (MEDIUM)

// Question 3 : Given an integer array nums, find a subarray that has the largest
// product, and return the product. The test cases are generated so that the answer will
// fit in a 32-bit integer. [link]

// Note - This Qs might feel difficult as a beginner because it uses DP approach.

// Examples:
// Input: nums = [2,3,-2,4]
// Output: 6
// Explanation: [2,3] has the largest product 6.

// Input: intervals =nums = [-2,0,-1]
// Output: 0
// Explanation: The result cannot be 2, because [-2,-1] is not a subarray.

#include<iostream>
#include<climits>
using namespace std;


// TC: O(N*N*N), SC: O(1)
void largestProduct1(int *nums, int size){
  int maxPro = INT_MIN;
  int pro;
  // start end -> starting and ending of subarrays
  for (int start = 0; start<size; start++){
    for (int end = start; end<size; end++){
      pro = 1;
      // travering each subarray and calculating product
      for (int i = start; i<=end; i++){
        pro = pro * nums[i];
      }
      // updaing product
      maxPro = max(pro, maxPro);
    }
  }
  cout<<maxPro<<endl;
}

// TC: O(N*N), SC: O(1)
void largestProduct2(int *nums, int size){
  int maxPro = INT_MIN;
  int pro;
  for (int i = 0; i<size; i++){
    pro = 1;
    for (int j = i; j<size; j++){
      // optimizing the product calculation by using previously calculated subarray product each step
      pro = pro * nums[j];
      maxPro = max(pro, maxPro);
    }
  }
  cout<<maxPro<<endl;
}

// TC: O(N), SC: O(N)
void largestProduct3(int *nums, int size){
  int maxPro = INT_MIN;
  int pro = 1;
  // using kadane's algorithm for dp
  for (int i = 0; i<size; i++){
    // we calculate the product at each step
    pro = nums[i] * pro;
    // and update if product is larger
    maxPro = max(pro, maxPro);
    // MAIN POINT: if the product is -ve we don't include that subarray and reinitalize it to 1 
    // cuz the prev subarray will never give me +ve or larger value so it will not participate in 
    // largest sum
    if (pro < 1){
      pro = 1;
    }
  }
  cout<<maxPro<<endl;
}

int main(){
  int nums[] = {2, 3, -2, 4};
  int size = sizeof(nums)/sizeof(int);
  
  int nums2[] = {-2, 0, -1};
  int size2 = sizeof(nums2)/sizeof(int);

  largestProduct1(nums, size);
  largestProduct1(nums2, size2);
  largestProduct2(nums, size);
  largestProduct2(nums2, size2);
  largestProduct3(nums, size);
  largestProduct3(nums2, size2);

  return 0;
}
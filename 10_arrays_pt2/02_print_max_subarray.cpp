#include <iostream>
#include <climits>  // To use INT_MIN
using namespace std;

// Time Complexity for Brute Force Approach is O(n^3);
void printMaxSubarray1(int* arr, int n){
  int sum = 0;
  // let maxSum be minimum ie. INT_MIN
  int maxSum = INT_MIN;
  for (int start = 0; start<n; start++){
    for (int end = start; end<n; end++){
      // calculate every possible sum
      sum = 0;
      for (int i = start; i<=end; i++){
        sum += arr[i];
      }
      // update maxSum if sum is greater
      maxSum = max(sum, maxSum);
    }
  }
  // print max sum
  cout<<"Maximum Sum is " << maxSum<<endl;
}

// Time Complexity : O(n^2)
void printMaxSubarray2(int* arr, int n){
  int currSum = 0;
  // let maxSum be minimum ie. INT_MIN
  int maxSum = INT_MIN;
  for (int start = 0; start<n; start++){
    currSum = 0;
    for (int end = start; end<n; end++){
      // rolling sum... rather than calculating new sum we just keep adding one more value
      currSum += arr[end];
      maxSum = max(currSum, maxSum);
    }
  }
  // print max sum
  cout<<"Maximum Sum is " << maxSum<<endl;
}

// Using Kadane's Algorithm (Dynamic Programming)
void printMaxSubarray3(int* arr, int n){
  int currSum = 0;
  int maxSum = INT_MIN;
  for(int i = 0; i<n; i++){
    currSum += arr[i];
    maxSum = max(currSum, maxSum);

    if (currSum<0){
      currSum = 0;
    }
  }
  cout << "Maximum sum using Kadane's algorithm is: "<< maxSum;
}

int main(){
  // given array
  int arr[] = {2, -3, 6, -5, 4, 2};
  int size = sizeof(arr)/sizeof(int);

  printMaxSubarray1(arr, size);
  printMaxSubarray2(arr, size);
  printMaxSubarray3(arr, size);
  return 0;
}
#include <iostream>
using namespace std;

// 1. n>2
// 2. We need  the min of (largest on left and largest on right) for each bar = X (say)
// 3. trap water = X - barHeight 
// 4. trap water should be +ve

int trappedWater(int* heights, int n){
  int leftMax[20000], rightMax[20000];
  leftMax[0]= heights[0]; // INT_MIN in mind
  rightMax[n-1] = heights[n-1]; // INT_MIN in  mind

  for (int i = 1; i<n; i++){
    leftMax[i] = max(leftMax[i-1], heights[i-1]);
  }
  for (int i = n-2; i>=0; i--){
    rightMax[i] = max(rightMax[i+1], heights[i+1]); 
  }
  int trapWater = 0;
  for (int i = 0; i<n; i++){
    int currwater = min(leftMax[i], rightMax[i]) - heights[i];
    if (currwater>0){
      trapWater+=currwater;
    }
  }
  return trapWater;
}
// Time Complexity - O(n+n+n) = 3n = n, Space Complexity - O(n+n) = 2n = n
int main(){
  int arr[] = {4, 2, 0, 6, 3, 2, 5};
  int arr2[] = {4, 3, 2, 1};

  int size = sizeof(arr)/sizeof(int);
  int size2 = sizeof(arr2)/sizeof(int);

  cout<<trappedWater(arr, size)<<endl;
  cout<<trappedWater(arr2, size2)<<endl;

  return 0;
}
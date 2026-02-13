// Question 1 : Write a recursive function to perform Binary Search.
// Input : arr[] = {1, 2, 3, 4, 5, 6, 7}, n = 7, key = 5
// Output : 4 (index of key)
// *Use the starting index & ending index logic used in rotated, sorted array Qs.
#include <iostream>
using namespace std;

int binarySearch(int* arr, int start, int end, int target){
  if (start>end) return -1;

  int mid = start + (end-start)/2;

  if (arr[mid] == target) 
    return mid;
  else if(arr[mid]>target)
    return binarySearch(arr, start, mid-1, target);
  else
    return binarySearch(arr, mid+1, end, target);
}
int main(){
  int arr[] = {1, 2, 3, 4, 5, 6, 7};
  int n= 7;
  int key = 5;
  cout<<binarySearch(arr, 0, n-1, key);
  return 0;
}
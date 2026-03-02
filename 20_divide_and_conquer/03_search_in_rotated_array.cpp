#include <iostream>
using namespace std;

int search(int arr[], int si, int ei, int target){ // O(log n)
  if (si>ei) return -1;

  int mid = si + (ei-si)/2;

  if (arr[mid] == target) return mid;
  else if(arr[si]<arr[mid]){ // left side is sorted
    if (arr[si] <= target && target< arr[mid]){ // checking if target is in sorted half
      return search(arr, si, mid-1, target); // searching sorted half
    }else{
      return search(arr, mid+1, ei, target); // seraching unsorted half
    }
  }else{  // right side is sorted
    if (arr[mid]<target && target<=arr[ei]){ 
      return search(arr, mid+1, ei, target);
    }else{
      return search(arr, si, mid-1, target);
    }
  }
}
int main(){
  int arr[] = {4, 5, 6, 7, 0, 1, 2};
  int size = sizeof(arr)/sizeof(int);
  int target = 0;
  cout<< search(arr, 0,  size-1, target);
  return 0;
}
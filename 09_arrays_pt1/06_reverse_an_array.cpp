#include <iostream>
using namespace std;

void reverseWithExtraSpace(int* arr, int n); // Time Complexity: O(n), Space Complexity: O(n) (extra array)
void reverseWithoutExtraSpace(int* arr, int n); // Time Complexity: O(n), Space Complexity: O(1)

void reverseWithExtraSpace(int* arr, int n){
  // declare copy arr
  int copy[n];

  // loop and copy ele to new array
  for (int i = 0; i<n; i++){
    // copy last ele to 1st, so on...
    copy[i] = arr[n-i-1];
  }

  // loop and overwrite original array from copy array
  for (int i = 0; i<n; i++){
    arr[i] = copy[i];
  }
}

void reverseWithoutExtraSpace(int* arr, int n){
  // loop half of the array 
  for (int i = 0; i<n/2; i++){
    // swap first and last ele
    swap(arr[i], arr[n-i-1]);
  }
}

int main(){
  // given array
  int arr[] = {5, 6, 12, 55, 2, 1};
  int n = sizeof(arr)/sizeof(int);
  
  // reverse arr
  // reverseWithExtraSpace(arr, n);
  reverseWithoutExtraSpace(arr, n);

  // print reversed arr
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}
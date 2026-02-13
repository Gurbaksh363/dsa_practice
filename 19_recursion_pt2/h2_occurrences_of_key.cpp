// Question 2: For a given integer array of size N. You have to find all the occurrences
// (indices) of a given element (Key) and print them.
// Use a recursive function to solve this problem.
// Sample Input : arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2}, key = 2
// Sample Output: 1 5 7 8

#include <iostream>
using namespace std;

void occurr(int* arr, int n, int i, int key){
  if (i==n){
    return;
  }
  if (arr[i] == key) cout<<i<<" ";
  occurr(arr, n, i+1, key);
}
int main(){
  int arr[] = {3, 2, 4, 5, 6, 2, 7, 2, 2};
  int size = sizeof(arr)/sizeof(int);
  int key = 2;
  occurr(arr, size, 0, key);
  return 0;
}
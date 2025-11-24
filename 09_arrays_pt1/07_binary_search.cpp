#include <iostream>
using namespace std;

int binarySearch(int* arr, int n, int key){
  // start and end indexes defines virtual arr we are searching
  int start = 0;
  int end = n-1; 
  while (start<=end){
    // mid index to access the center of virtual array
    int mid = start + (end - start)/2;
    // return mid if middle ele is key
    if (arr[mid]==key){
      return mid;
    }// update start of virtual arr if mid ele is less than key
    else if (arr[mid]<key){
      start = mid+1;
    }// again narrow down virtual arr if mid ele is greater than key
    else{
      end = mid -1;
    }
  }
  // return -1 if key not found
  return -1;
}

int main(){
  // given sorted array 
  int arr[] = {2, 4, 5, 7, 9, 34, 66, 88, 542};
  int size = sizeof(arr)/sizeof(int);

  // search 66 and 13
  cout<<binarySearch(arr, size, 66)<<endl;
  cout<<binarySearch(arr, size, 13)<<endl;
  return 0;
}
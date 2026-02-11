#include <iostream>
using namespace std;

void printSubarray(int* arr, int n){
  // For each element of array , 0, 1, 2, 3, 4
  for(int start = 0; start<n; start++){
    // for each sub pair formed, 00, 01, 02, 03, 04,  11, 12, ...
    for (int end = start; end<n; end++){
      // cout<<"("<<start<<","<<end<<"), ";
      // looping start to end of each subpair, (indexes of array) 0, 01, 012, 0123, 01234, 1, 12,....
      for (int i = start; i<=end; i++){
        cout<<arr[i];
      }
      cout<<", ";
    }
    cout<<endl;
  }
}

int main(){
  // given array
  int arr[5] = {1, 2, 3, 4, 5};
  int size = 5;

  // print subarray
  printSubarray(arr, size);
  return 0;
}
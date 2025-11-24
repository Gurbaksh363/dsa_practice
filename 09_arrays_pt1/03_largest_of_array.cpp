#include <iostream>
using namespace std;

int main(){
  // given array
  int arr[] = {5, 6, 3, 2, 7, 4, 2 , 4};

  // assume first ele is largest
  int max = arr[0];

  // loop and compare with other elements of array and update max
  for (int i = 0; i<sizeof(arr)/sizeof(int); i++){
    if (arr[i]>max){
      max = arr[i];
    }
  }

  // print largest element
  cout<<max;
  return 0;
}
// Time Complexity: O(n)
// Space Complexity: O(1)
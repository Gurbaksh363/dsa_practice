#include <iostream>
using namespace std;

int linearSearch(int* ptr, int n, int key){
  // loop and compare each ele with key
  for (int i = 0; i<n; i++){
    // return index if key is present
    if (key == ptr[i]){
      return i;
    }
  }
  // return -1 if ele not found;
  return -1;
}
int main(){
  // given array
  int arr[] = {34, 5, 12, 4, 1, 78, 42};
  int size = sizeof(arr)/sizeof(int);

  // search 12 and 52 in arr
  cout<< linearSearch(arr, size, 12)<<endl; 
  cout<< linearSearch(arr, size, 52)<<endl;
  return 0;
}
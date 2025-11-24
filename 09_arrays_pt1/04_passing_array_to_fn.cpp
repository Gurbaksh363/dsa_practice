#include <iostream>
using namespace std;

void print(int *ptr, int n){  // or (int ptr[])
  // print size of ptr
  int size = sizeof(ptr);
  cout<< size<<endl; // it is size of ptr not of array , so we have to manually pass arr size;

  // print arr
  for(int i = 0; i<size; i++){
    cout<<ptr[i]<<" ";
  }
}
int main(){
  int arr[10] = {2, 4, 5, 1, 3};

  cout<<arr<<endl; // prints address to 1st ele.

  // pass array (ptr to first arr ele) 
  print(arr, 10);
  
  return 0;
}
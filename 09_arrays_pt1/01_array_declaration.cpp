#include <iostream>
using namespace std;

int main(){
  int arr[10]; // garbage values

  int arr2[] = {23, 4, 5}; // 23, 4, 5, ...garbage values 

  int arr3[10] = {5, 6, 7}; // 5, 6, 7, ... initialized with 0s

  int n;              
  cout<<"Enter the length of array:"<<endl;
  cin>>n;
  int arr4[n];        // runtime array declaration allowed in new cpp only

  for (int i = 0; i<12; i++){
    cout<<arr3[i]<<" ";
  }
  return 0;
}
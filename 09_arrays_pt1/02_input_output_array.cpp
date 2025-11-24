#include <iostream>
using namespace std;

int main(){
  // input size of array
  int n;
  cout<<"Enter length of the arr: "<<endl;
  cin>> n;

  // Declare array of size n at runtime
  int arr[n]; 
  // loop to take input
  cout<<"Enter elements: "<<endl;
  for (int i = 0; i<n; i++){
    cin>> arr[i];
  }

  // loop to print values;
  for(int i = 0; i<n; i++){
    cout<<arr[i]<<" ";
  }

  return 0;
}
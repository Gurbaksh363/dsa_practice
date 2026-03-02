#include <iostream>
#include <vector>
using namespace std;

void print(int arr[], int size){
  for(int i = 0; i<size; i++){
    cout<<arr[i]<<" ";
  }
  cout<<endl;
}
int partition(int arr[], int si, int ei){
  int i = si - 1; // used to maintain correct place of smaller eles than pivot
  int pivot = arr[ei];
  for (int j = si; j<ei; j++){
    // checking if current element is lesser then movingt to forward place
    if (arr[j]<= pivot){
      i++;
      swap(arr[i], arr[j]);
    }
  }
  i++; // placing pivot to correct place
  swap(arr[i], arr[ei]);
  return i;
}
void quickSort(int arr[], int si, int ei){
  if (si>=ei) return;

  int pivotIdx = partition(arr, si, ei);

  quickSort(arr, si, pivotIdx-1);
  quickSort(arr, pivotIdx+1, ei);
}
int main(){
  int arr[] = {6, 3, 7, 5, 2, 4};
  int size = sizeof(arr)/sizeof(int);
  quickSort(arr, 0, size-1);
  print(arr, size);
  
  return 0;
}
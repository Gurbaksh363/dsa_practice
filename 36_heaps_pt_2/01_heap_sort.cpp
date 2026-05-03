#include <iostream>
#include <vector>

using namespace std;

// ************** n ko pass krna is super important in  HEAP SORT ******************
void heapify(int i, vector<int>& arr, int n){  // top to down
  int left = 2*i+1;
  int right = 2*i+2;
  int maxI = i;
  if(left<n && arr[left]>arr[maxI]) maxI = left;       // > to < for min heap
  if(right<n && arr[right]>arr[maxI]) maxI = right;    // > to < for min heap
  
  if(maxI!=i){       
    swap(arr[i], arr[maxI]);
    heapify(maxI, arr, n);
  }
}
void heapSort(vector<int>& arr){
  int n = arr.size();

  // step1: build heap by fixing from (n/2)-1 to 0 (all nodes except leaf nodes)
  for(int i = (n/2)-1; i>=0; i--){
    heapify(i, arr, n);
  }
  
  // step2: taking eles to correct position by swapping first and last and then fixing heap
  for(int i = n-1; i>=0; i--){
    swap(arr[0], arr[i]);
    heapify(0, arr, i);
  }
}

void print(vector<int> arr){
  for(int ele: arr){
    cout<<ele<<" ";
  }
  cout<<endl;
}
int main(){
  vector<int> arr = {1, 4, 2, 5, 3};   // cbt (normal array)
  heapSort(arr);
  print(arr);
  
  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_set>
using namespace std;

void printUnion(vector<int> arr1, vector<int>arr2){
  unordered_set<int> s;
  for(int ele: arr1){
    s.insert(ele);
  }
  for(int ele: arr2){
    s.insert(ele);
  }
  cout<<"\nUnion of two arrays: ";
  for(int ele: s){
    cout<<ele<<" ";
  }
}
void printIntersection(vector<int> arr1, vector<int>arr2){
  unordered_set<int> s;
  for(int ele: arr1){
    s.insert(ele);
  }
  cout<<"\nIntersection of two arrays: ";
  for(int ele: arr2){
    if(s.count(ele)){
      cout<<ele<<" ";
       s.erase(ele);    // so duplicate print does not occur
    }
  }
}
int main(){
  vector<int> arr1 = {7, 3, 9};
  vector<int> arr2 = {6, 3, 9, 2, 9, 4};
  printUnion(arr1, arr2);
  printIntersection(arr1, arr2);
  return 0;
}
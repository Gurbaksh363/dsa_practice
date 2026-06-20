#include <iostream>
#include <unordered_map>
using namespace std;

int main(){
  // int arr[] = {1, 3, 2, 5, 1, 3, 1, 5, 1};
  int arr[] = {1, 2};
  // int n = 9;
  int n = 2;
  unordered_map<int, int> m;

  for(int i=0; i<n; i++){
    m[arr[i]]++;
  }
  for(pair<int, int> ele: m){
    if(ele.second > n/3){
      cout<<ele.first<<" ";
    }
  }

  return 0;
}
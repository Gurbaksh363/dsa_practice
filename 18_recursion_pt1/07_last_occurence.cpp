#include <iostream>
#include <vector>
using namespace std;

int lastOccur(vector<int>& v, int i, int target){
  // base case
  if (i==v.size()) return -1;

  // faith
  int idx = lastOccur(v, i+1, target);
  // kaam (later)
  if (idx==-1){
    if (v[i]==target){
      return i;
    }
  }
  return idx;
}

int main(){
  vector<int> v = {1, 2, 3, 3, 3, 4, 5, 5};

  cout<<lastOccur(v, 0, 3)<<endl;
  cout<<lastOccur(v, 0, 5)<<endl;
  cout<<lastOccur(v, 0, 6)<<endl;

  return 0;
}
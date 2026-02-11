// first occurence of element in a vector
#include <iostream>
#include <vector>
using namespace std;

int firstOccur(vector<int>& v,  int i,  int target){
  if (i== v.size()){
    return -1;
  }
  
  if (v[i] == target){
    return i;
  }
  return firstOccur(v, i+1, target);
}

int main(){
  vector<int> v = {1, 2, 3, 3, 3, 5, 5};

  cout<<firstOccur(v, 0, 3)<<endl;
  cout<<firstOccur(v, 0, 5)<<endl;
  cout<<firstOccur(v, 0, 6)<<endl;
  return 0;
}
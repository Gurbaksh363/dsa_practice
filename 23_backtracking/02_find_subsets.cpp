#include <iostream>
using namespace std;

void printSubsets(string str, string subset){
  if (str.length()==0){
    cout<<subset<<endl;
    return;
  }
  // 2 choices: include current char or not
  char ch = str[0];
  // include and reducing string len
  printSubsets(str.substr(1, str.length()-1), subset+ch);
  // exclude and reducing string len
  printSubsets(str.substr(1, str.length()-1), subset);
}

int main(){
  printSubsets("abc","");
  return 0;
}

// TC: O(2^N) SC: O(N)
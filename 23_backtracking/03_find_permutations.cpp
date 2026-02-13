#include <iostream>
using namespace std;

void permutation(string str, string ans){
  int n= str.size();
  if (n==0){
    cout<<ans<<endl;
    return;
  }
  for(int i=0; i<str.size(); i++){
    char ch= str[i];
    string nextStr = str.substr(0, i) + str.substr(i+1, n-i-1) ;  // "abcdefg" i=2, "ab" 0 to i,  "defg" i+1 to n-i-1
    permutation( nextStr , ans + ch);
  }
}

int main(){
  permutation("abc", "");
  return 0;
}
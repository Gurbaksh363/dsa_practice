// print all binary strings of size N without any consecutive 1s
#include <iostream>
using namespace std;

void generateBinary(int n, string ans, int lastPlace){
  if (n==0){
    cout<<ans<<endl;
    return;
  }

  if (lastPlace==0){
    generateBinary(n-1, ans+'0', 0);
    generateBinary(n-1, ans+'1', 1);
  } 
  else generateBinary(n-1, ans + '0', 0);
}


void generateBinary2(int n, string ans){
  if (n==0){
    cout<<ans<<endl;
    return;
  }
  // lastPlace = 0 we have 2 choices:  1/0
  if (ans.length()==0 || ans[ans.size()-1]!='1'){  // we also check for empty string
    generateBinary2(n-1, ans+'0');
    generateBinary2(n-1, ans+'1');
  } 
  // lastPlace = 1 we have 1 choice: 0
  else generateBinary2(n-1, ans+'0');
}

int main(){
  // generateBinary(3, "", 0);
  generateBinary2(3, "");
  return 0;
}
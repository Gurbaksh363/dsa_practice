#include <iostream>
using namespace std;

int tilingProblem(int n){  // 2 * n
  if (n==0 || n==1){
    return 1;
  }
  // vertically
  int ans1 = tilingProblem(n-1); // 2* n-1
  // horizontally
  int ans2 = tilingProblem(n-2); // 2 * n-2
  return ans1 + ans2;
}
int main(){

  cout<<tilingProblem(5);
  
  return 0;
}
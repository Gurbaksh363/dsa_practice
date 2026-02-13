#include <iostream>
using namespace std;

void towerOfHanoi(int n, string src, string helper, string dest){
  if (n==1){
    cout<<"transfer disk "<<n<<" from "<<src<< " to "<<dest<<endl;
    return;
  }
  // transfer top n-1 disks from src to helper using dest as 'helper'
  towerOfHanoi(n-1, src, dest, helper);
  // transfer nth disc from src to dest
  cout<<"transfer disk "<<n<<" from "<<src<< " to "<<dest<<endl;
  // transfer top  n-1 disks from helper to dest using src as 'helper'
  towerOfHanoi(n-1, helper, src, dest);

}
int main(){
  towerOfHanoi(3, "A", "B", "C");
  return 0;
}
#include <iostream>
#include<map>
#include <string>
using namespace std;

int main(){
  map<int, string> m;

  m[110] = "neha";
  m[101] = "rahul";
  m[131] = "rahul";

  m[101] = "rajat";
  cout<<m[101]<<endl;
  cout<<m[100]<<endl; // nothing will be printed

  cout<<m.count(101)<<endl; // will return 1 if key is present, if not 0;

  for(auto it: m){
    cout<<it.first<<" "<<it.second<<endl;
  }
   
  return 0;
}
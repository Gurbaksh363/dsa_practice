#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;

int main(){
  unordered_map<string, int> m;

  m["India"] = 150;
  m["China"] = 150;
  m["Nepal"] = 100;
  m["UK"] = 20;
  m["US"] = 50;

  for(pair<string, int> it: m){
    cout<<it.first<<" "<<it.second<<endl;
  }
  if(m.count("Canada")){
    cout<<"Canada exists\n";
  }else{
    cout<<"Canada does not exists\n";
  }
  return 0;
}
#include <iostream>
#include <set>
using namespace std;

int main(){
  set<int> s;
  s.insert(4);
  s.insert(1);
  s.insert(2);
  s.insert(3);
  s.insert(1);
  s.insert(1);
  s.insert(1);
  cout<<s.size()<<endl;  // 4
  s.erase(3);
  if(s.find(5)!=s.end()){
    cout<<"5 exists\n";
  }else{
    cout<<"5 does not exists\n";
  }
  for(auto el: s){
    cout<<el<<" ";
  }
  cout<<endl;
  return 0;
}
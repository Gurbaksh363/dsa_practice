#include <iostream>
using namespace std;

// TC: O(n)  SC: O(1)
void removeDup(string str, string ans,  int i, bool map[]){
  if (i==str.length()){
    cout<<ans<<endl;
    return;
  }
  int mapIdx = (int)str[i] - 'a';
  if (map[mapIdx]){
    removeDup(str, ans, i+1, map );
  }else{
    map[mapIdx] = true;
    removeDup(str, ans+str[i], i+1, map);
  }
}

void removeDup2(string str, string ans, bool map[]){
  if (str.size() == 0){
    cout<<ans<<endl;
    return;
  }
  int n = str.size();
  char lastCh = str[n-1];
  int mapIdx = (int) (lastCh - 'a');
  str = str.substr(0, n-1);   //      Parameters: __pos – Index of first character & __n – Number of characters in substring



  if (map[mapIdx]){
    removeDup2(str, ans, map );
  }else{
    map[mapIdx] = true;
    removeDup2(str, lastCh+ans, map);
  }
  
}
int main(){
  string str = "appnnacollege";
  bool map[26] = {false};
  // removeDup(str, "", 0,  map);
  removeDup2(str, "", map);
  return 0;
}
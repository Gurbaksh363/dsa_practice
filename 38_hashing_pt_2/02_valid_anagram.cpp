#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

bool validAnagram(string s, string t){
  if(s.size() != t.size())return false;
  unordered_map<char, int> m;
  // creating map for string s
  for(int i = 0; i<s.size(); i++){
    m[s[i]]++;
  }

  // iterating t and reducing freq for every match
  for(int i = 0; i<t.size(); i++){
    if(!m.count(t[i])){
      return false;
    }else{
      m[t[i]]--;
      if(m[t[i]]==0){
        m.erase(t[i]);
      }
    }
  }
  return m.size()==0;
}
int main(){
  string s = "race";
  string t = "care";
  cout<<validAnagram(s, t);

  return 0;
}
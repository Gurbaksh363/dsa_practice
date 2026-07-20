#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
  public:
  unordered_map<char, Node*> children;
  bool endOfWord;

  Node(){
    endOfWord = false;
  }
};

class Trie{
  public:
  Node* root;
  Trie(){
    root = new Node();
  }
  void insert(string key){
    Node* temp = root;
    for(int i = 0; i<key.size(); i++){
      if(!temp->children.count(key[i])){
        temp->children[key[i]] = new Node();
      }
      temp = temp->children[key[i]];
    }
    temp->endOfWord = true;
  }
};

int count(Node* root){
  int ans = 0;
  for(auto p: root->children){
    ans += count(p.second);
  }
  return ans + 1;
}
int countUniqueSubstr(string str){
  // 1) create suffix array
  vector<string> suffix;
  for(int i = 0; i<str.size(); i++) 
    suffix.push_back(str.substr(i));

  // 2) create trie of suffix
  Trie trie;
  for(int i = 0; i<suffix.size();i++){
    trie.insert(suffix[i]);
  }
  // 3) count nodes of trie + 1 that is ans
  return count(trie.root);

}
int main(){
  string str = "ababa";
  cout<<countUniqueSubstr(str)<<endl;
  return 0;
}
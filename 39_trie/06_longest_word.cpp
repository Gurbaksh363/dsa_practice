// longest word such that all of its prefixes exist in array
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
void longestWordHelper(Node* root, string& ans, string temp){
  for(pair<char, Node*> child : root->children){
    if(child.second->endOfWord == true){
      temp += child.first;
      if(temp.size() > ans.size()){
        ans = temp;
      }else if(temp.size()==ans.size() && temp<ans){
        ans = temp;
      }
      longestWordHelper(child.second, ans, temp);
      temp.pop_back();
    }
  }
}
string longestWord(vector<string>words){
  // build trie
  Trie trie;
  for(int i =0; i<words.size(); i++){
    trie.insert(words[i]);
  }

  // find longest word
  string ans = "";
  longestWordHelper(trie.root, ans, "");
  return ans;
}
int main(){
  vector<string> words = {"a", "banana", "app", "appl", "ap", "apply", "apple"};
  
  cout<<longestWord(words);
  return 0;
}
#include <iostream>
#include <vector>
#include <unordered_map>
#include <string>
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
      char ch = key[i];
      if(!temp->children.count(ch)){
        temp->children[ch] = new Node();
      }
      temp = temp->children[ch];
    }
    temp->endOfWord = true;
  }
  bool search(string key){
    Node* temp = root;
    for(int i = 0; i<key.size(); i++){
      char ch = key[i];
      if(!temp->children.count(ch)) return false;
      temp = temp->children[ch];
    }
    return temp->endOfWord==true;
  }
};

bool helper(Trie trie, string key){
  if(key.size()==0) return true;
  
  for(int i = 0; i<key.size(); i++){
    string first = key.substr(0, i+1); // startIndex, length
    string second = key.substr(i+1);  
    // if first string trie exist krdi aa? te je krdi aa tan next call
    if(trie.search(first) && helper(trie, second)){
      return true;
    }

  }
  return false;
}
bool wordBreak(vector<string> dict, string key){
  // 1) build trie
  Trie trie;
  for(int i = 0;i<dict.size(); i++){
    trie.insert(dict[i]);
  }
  return helper(trie, key);
}
int main(){
  vector<string> words = {"i", "like", "sam", "samsung", "mobile", "ice"};

  string key = "ilikesamsung";
  string key2 = "iamsung";
  cout<<"ilikesamsung:"<<wordBreak(words, key)<<endl;
  cout<<"iamsung:"<<wordBreak(words, key2)<<endl;

  return 0;
}
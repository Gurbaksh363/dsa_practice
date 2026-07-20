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


bool startsWith(Trie trie,string prefix){
  Node* temp = trie.root;
  for(int i = 0; i<prefix.size(); i++){
    if(!temp->children.count(prefix[i])){
      return false;
    }
    temp = temp->children[prefix[i]];
  }
  return true;
}
int main(){
  vector<string> words = {"apple", "app", "mango", "man", "woman"};
  Trie trie;
  for(int i = 0; i<words.size(); i++){
    trie.insert(words[i]);
  }
  cout<<startsWith(trie, "app")<<endl;
  cout<<startsWith(trie, "moon")<<endl;
  cout<<startsWith(trie, "wom")<<endl;

  return 0;
}
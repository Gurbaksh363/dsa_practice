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
  // void insertHelper(string key, Node* curr){
  //   if(key==""){
  //     curr->endOfWord = true;
  //     return;
  //   } 
  //   char ch = key[0];
  //   if(!curr->children.count(ch)){
  //     curr->children[ch] = new Node();
  //   }
  //   insertHelper(key.substr(1), curr->children[ch]);
  // }
  void insert(string key){  // O(L) and for inserting  n keys O(n*L)
    // insertHelper(key, root);
    Node* temp = root;
    for(int i = 0; i<key.size(); i++){
      if(!temp->children.count(key[i])){
        temp->children[key[i]] = new Node();
      }
      temp = temp->children[key[i]];
    }
    temp->endOfWord = true;
  }
  bool search(string key){
    Node* temp = root;
    for(int i = 0; i<key.size(); i++){
      if(!temp->children.count(key[i])){
        return false;
      }
      temp = temp->children[key[i]];
    }

    return temp->endOfWord==true;
  }
};


int main(){
  vector<string> words = {"the", "a", "there", "their", "any", "thee"};

  Trie trie;
  for(int i =0; i<words.size(); i++){
    trie.insert(words[i]);
  }
  cout<<trie.search("there")<<endl;
  cout<<trie.search("any")<<endl;
  cout<<trie.search("ant")<<endl;
  return 0;
}
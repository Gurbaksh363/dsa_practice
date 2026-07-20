// find shortest unique prefix for each word (no words is prefix of another)
#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

class Node{
  public:
  unordered_map<char, Node*> children;
  bool end;
  int freq;

  Node(){
    end = false;
  }
};

class Trie{
  public:
  Node* root;
  Trie(){
    root = new Node();
    root->freq = -1;
  }
  void insert(string key){
    Node* temp = root;
    for(int i = 0; i<key.size(); i++){
      if(!temp->children.count(key[i])){
        temp->children[key[i]] = new Node();
        temp->children[key[i]]->freq = 1;
      }else{
        temp->children[key[i]]->freq++;
      }
      temp = temp->children[key[i]];
    }
    temp->end = true;
  }
};

vector<string> prefix(Trie trie, vector<string> words){
  vector<string> ans;
  for(int i=0; i<words.size(); i++){
    string word = words[i];
    Node* temp = trie.root;
    bool found = false;
    for(int j = 0; j<word.size(); j++){
      if(temp->children[word[j]]->freq==1){
        ans.push_back(word.substr(0, j+1));
        found = true;
        break;
      }
      temp = temp->children[word[j]];
    }
    if(!found) ans.push_back(word);
  }

  return ans;
}
int main(){
  vector<string> words = {"zebra", "dog", "duck", "dove"};
  Trie trie;
  for(int i = 0; i<words.size(); i++){
    trie.insert(words[i]);
  }
  vector<string> ans = prefix(trie, words);
  for(string ele: ans){
    cout<<ele<<" ";
  }
  cout<<endl;
  return 0;
}
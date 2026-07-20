//Question 1: MEDIUM
// Group Anagrams Together
// Given an array of strings strs, group the anagrams together. You can return the answer in any
// order.
// An Anagram is a word or phrase formed by rearranging the letters of a different word or
// phrase, typically using all the original letters exactly once.
// Sample Input 1: strs = ["eat","tea","tan","ate","nat","bat"]
// Sample Output 1 : [["bat"], ["nat", "tan"], ["ate", "eat", "tea"]]
// Sample Input 2: strs = [""]
// Sample Output 2: [[]]
// Sample Input 3: strs = ["a"]
// Sample Output 3: [["a"]]
#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Node{
  public:
  unordered_map<char, Node*> children;
  bool endOfWord;
  vector<string> oriWords;
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
  void insert(string key, string word){
    Node* temp = root;
    for(int i = 0; i<key.size(); i++){
      if(!temp->children.count(key[i])){
        temp->children[key[i]] = new Node();
      }
      temp = temp->children[key[i]];
    }
    temp->endOfWord = true;
    temp->oriWords.push_back(word);
  }
  void helper(Node* root, vector<vector<string>>& ans){
    if(root->endOfWord){
      ans.push_back(root->oriWords);
    }
    for(auto child: root->children){
      helper(child.second, ans);
    }
  }
  vector<vector<string>>groupAnas(){
    vector<vector<string>> ans;
    helper(root, ans);
    return ans;
    
  }
};
int main(){
  vector<string> words = {"eat","tea","tan","ate","nat","bat"};

  Trie trie;
  for(int i = 0; i<words.size(); i++){
    string key = words[i];
    sort(key.begin(), key.end());
    trie.insert(key, words[i]);
  }
  vector<vector<string>> ans = trie.groupAnas();
  for(int i =0; i<ans.size(); i++){
    for(int j = 0; j<ans[i].size(); j++){
      cout<<ans[i][j]<<" ";
    }
    cout<<endl;
  }

  return 0;
}
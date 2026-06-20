#include <iostream>
#include <string>
using namespace std;

class Node{
  public:
  string key;
  int val;
  Node* next;

  Node(string key, int val){
    this->key = key;
    this->val = val;
    next = NULL;
  }

  ~Node(){        // DESTRUCTOR
    if(next!=NULL){
      delete next;
    }
  }
};


class HashTable{
  int totSize;
  int currSize;
  Node** table;
  int hashFunction(string key){
    int idx = 0;
    for(int i = 0; i<key.size(); i++){
      idx = (idx + (key[i] *key[i] )) % totSize;
    }
    return idx % totSize;
  }
  void rehash(){
    // preserving old table
    Node** oldTable = table;
    int oldSize = totSize;

    // create new table and intializing to NULL
    totSize *= 2;
    currSize = 0;
    table = new Node*[totSize];
    for(int i = 0; i<totSize; i++){
      table[i] = NULL;
    }
    // updating new table
    for(int i = 0; i<oldSize; i++){
      Node* curr = oldTable[i];
      while(curr!=NULL){
        insert(curr->key, curr->val);
        curr = curr->next;
      }

      // deleting old table
      if(oldTable[i]!=NULL){
        delete oldTable[i];
      }
    }
    delete[] oldTable;
  }
  public:
  HashTable(int size=5){
    totSize = size;
    currSize = 0;
    table = new Node*[totSize];  // heap memory
    
    // intialize with NULL
    for(int i = 0; i<totSize; i++){
      table[i] = NULL;
    }
  }
  void insert(string key, int val){
    int idx = hashFunction(key);

    Node* newNode = new Node(key, val);

    newNode->next = table[idx];
    table[idx] = newNode;

    currSize++;
    double lambda = currSize/(double)totSize;  // Rehashing threshold
    if(lambda>1){
      rehash();     // O(n)
    }
  }
  int exists(string key){
    int idx = hashFunction(key);
    Node* curr = table[idx];
    while(curr!=NULL){
      if(curr->key == key){
        return true;
      }
      curr = curr->next;
    }
    return false;
  }
  int search(string key){
    int idx = hashFunction(key);
    Node* curr = table[idx];
    while(curr!=NULL){
      if(curr->key == key){
        return curr->val;
      }
      curr = curr->next;
    }
    return -1;
  }
  void erase(string key){
    int idx = hashFunction(key);

    Node* prev = NULL;
    Node* curr = table[idx];
    while(curr!=NULL){
      if(curr->key == key){
        // delete
        if(prev==NULL){
          table[idx] = curr->next;
        }else{
          prev->next = curr->next;
        }
      }
      prev = curr;
      curr = curr->next;
    }
  }
  void print(){
    for(int i = 0; i<totSize; i++){
      cout<<"idx "<<i<<" -> ";
      Node* curr = table[i];
      while(curr!=NULL){
        cout<<"("<<curr->key<<", "<<curr->val<<" ) -> ";
        curr = curr->next;
      }
      cout<<endl;
    }
    cout<<endl;
  }
  
};
int main(){
  HashTable ht;
  ht.insert("India", 150);
  ht.insert("China", 150);
  ht.insert("US", 50);
  ht.insert("Nepal", 10);
  ht.insert("UK", 20);

  if(ht.exists("India")){
    cout<<"Population of India is: "<<ht.search("India")<<endl;
  }
  if(ht.exists("China")){
    cout<<"Population of China is: "<<ht.search("China")<<endl;
  }
  if(ht.exists("Nepal")){
    cout<<"Population of Nepal is: "<<ht.search("Nepal")<<endl;
  }
  ht.print();
  
  ht.erase("US");
  ht.print();
  
  return 0;
}
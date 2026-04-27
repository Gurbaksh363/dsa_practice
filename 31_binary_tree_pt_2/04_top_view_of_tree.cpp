#include <iostream>
#include <queue>
#include <map>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

static int idx =  -1;

Node* buildTree(vector<int>& nodes){
  idx++;
  // base case
  if (nodes[idx] == -1){
    return NULL;
  }

  Node* currNode = new Node(nodes[idx]); // work
  currNode->left = buildTree(nodes); // we have faith it will create left subtree
  currNode->right = buildTree(nodes); // we have faith it will create right subtree

  return currNode;     // we are returning to access the tree

}

void topView(Node* root){
  if (root==NULL){
    return ;
  }

  queue<pair<Node*, int>> Q; // (node, hd)
  map<int, int> mp; // (hd, node->data)
  
  Q.push(make_pair(root, 0));
  while(!Q.empty()){
    pair<Node*, int> curr = Q.front();
    Q.pop();

    Node* currNode = curr.first;
    int currHD = curr.second;

    if (!mp.count(currHD)){  // HD is unique
      mp[currHD] = currNode->data;
    }

    if(currNode->left!=NULL){
      Q.push(make_pair(currNode->left, currHD-1 ));
    }
    if(currNode->right!=NULL){
      Q.push(make_pair(currNode->right, currHD+1 ));
    }
  }

  for(auto it: mp){
    cout<<it.second<<" ";
  }
  cout<<endl;

}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);
  
  topView(root);

  return 0;
}
#include <iostream>
#include <vector>
#include <queue>
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

int height(Node* root){
  // base case: see for smallerst prob like what to do of leaf node
  if (root==NULL){
    return 0;
  }
  int leftHt = height(root->left);
  int rightHt = height(root->right);

  return 1 + max(leftHt, rightHt);
}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);
  
  cout<<"Height of the tree: "<<height(root); // 3
  return 0;
}
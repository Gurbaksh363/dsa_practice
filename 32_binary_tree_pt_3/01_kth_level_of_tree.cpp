#include <iostream>
#include <vector>
// #include <pair>
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

void kthLevel(Node* root, int k, int currLevel){
  if (root==NULL){
    return ;
  }
  // optimization
  if (currLevel>k){
    return;
  }
  if (currLevel==k){
    cout<<root->data<<" ";
  }
  kthLevel(root->left, k, currLevel+1);
  kthLevel(root->right, k, currLevel+1);
}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, 7, -1, -1};
  Node* root = buildTree(nodes);

  kthLevel(root, 3, 1);
  return 0;
}
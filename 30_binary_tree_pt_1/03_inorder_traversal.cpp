#include <iostream>
#include <vector>
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

void preOrder(Node* root){
  if (root==NULL){
    return ;
  }

  cout<<root->data<< " ";
  preOrder(root->left);
  preOrder(root->right);
}

void inOrder(Node* root){
  if (root==NULL){
    return;
  }
  inOrder(root->left);
  cout<<root->data<<" ";
  inOrder(root->right);
}
int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);

  preOrder(root); // 1 2 4 5 3 6 
  cout<<endl;
  inOrder(root);  // 4 2 5 1 3 6 
  return 0;
}
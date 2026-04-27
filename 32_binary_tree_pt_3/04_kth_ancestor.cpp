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

int KthAncestor(Node* root, int n, int k){
  if(root==NULL){
    return -1;
  }
  if(root->data == n){
    return 0;
  }
  int leftLevel = KthAncestor(root->left, n, k);
  int rightLevel = KthAncestor(root->right, n, k);
  
  if(leftLevel == -1 && rightLevel==-1){
    return -1;
  }
  int validVal = leftLevel==-1 ? rightLevel:leftLevel;
  if(validVal+1==k){
    cout<<root->data<<endl;
  }
  return validVal+1;
 
}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);

  KthAncestor(root, 4, 2);
  KthAncestor(root, 4, 1);
  KthAncestor(root, 6, 1);
  return 0;
}
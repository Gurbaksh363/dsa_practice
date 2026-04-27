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

Node* LCA2(Node* root, int n1, int n2){ // O(n), O(1)
  if(root==NULL){
    return NULL;
  }
  if (root->data == n1 || root->data ==n2){
    return root;
  }
  Node* leftLCA = LCA2(root->left, n1, n2);
  Node* rightLCA = LCA2(root->right, n1, n2);
  
  if(leftLCA && rightLCA){
    return root;
  }
  return leftLCA == NULL ? rightLCA : leftLCA;
}

int distRootToNode(Node* root, int n){
  if(root==NULL){
    return -1;
  }
  if(root->data ==n){
    return 0;
  }
  int leftDist = distRootToNode(root->left, n);
  if(leftDist!=-1){
    return 1+leftDist;
  }
  int rightDist = distRootToNode(root->right, n);
  if(rightDist!=-1){
    return 1+rightDist;
  }
  return -1;
}

int minDist(Node* root, int n1, int n2){ // O(n)
  if (root==NULL){
    return -1;
  }
  // 1. lca
  Node* lca = LCA2(root,  n1, n2);
  // 2. return dist1 + dist2
  return distRootToNode(lca, n1) + distRootToNode(lca, n2);
}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);
  
  cout<<"Min Dist: "<<minDist(root, 4, 6)<<endl;
  cout<<"Min Dist: "<<minDist(root, 4, 5)<<endl;
  cout<<"Min Dist: "<<minDist(root, 5, 3)<<endl;
  return 0;
}
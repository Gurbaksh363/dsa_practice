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

bool isIdential(Node* root1, Node* root2){
  if(root1==NULL && root2==NULL){
    return true;
  }
  if(root1==NULL || root2==NULL){
    return false;
  }

  if (root1->data!=root2->data){
    return false;
  }
  return isIdential(root1->left, root2->left) && 
    isIdential(root1->right, root2->right);
}

bool isSubtree(Node* root, Node* subRoot){
  if (root==NULL && subRoot==NULL){
    return true;
  }
  if(root==NULL || subRoot==NULL){
    return false;
  }
  if (root->data==subRoot->data){
    // check identical
    if (isIdential(root, subRoot)){
      return true;
    }
  }
  bool isLeftSubtree = isSubtree(root->left, subRoot);
  if (!isLeftSubtree){
    return isSubtree(root->right, subRoot);
  }
  return true;
}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);

  Node* subRoot = new Node(2);
  subRoot->left = new Node(4);
  // subRoot->right = new Node(5);

  cout<< isSubtree(root, subRoot);
  return 0;
}
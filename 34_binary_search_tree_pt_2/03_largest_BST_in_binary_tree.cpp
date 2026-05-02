#include <iostream>
#include <climits>
using namespace std;

class Node{
  public:
  int data;
  Node* left, *right;

  Node(int val){
    data = val;
    left = right = NULL;
  }
};

class Info{
  public:
  bool isBST;
  int min;
  int max;
  int sz;
  Info(bool isBST, int min, int max, int sz){
    this->isBST = isBST;
    this->min = min;
    this->max = max;
    this->sz = sz;
  }
};

static int maxSz = 0;
Info* largestBST(Node* root){
  // BASE CASE STYLE 1:
  // if(root==NULL){
  //   return new Info(true, INT_MAX, INT_MIN, 0);
  // }

  // BASE CASE STYLE 2:
  if (root==NULL){
    return NULL;
  }
  if(root->left==NULL && root->right==NULL){
    return new Info(true, root->data, root->data, 1);
  }


  Info* leftInfo = largestBST(root->left);
  Info* rightInfo = largestBST(root->right);
  
  // calculating curr Info
  bool isCurrBST = leftInfo->isBST && rightInfo->isBST && root->data > leftInfo->max && root->data < rightInfo->min;
  int currMin = min(root->data, min(leftInfo->min, rightInfo->min));
  int currMax = max(root->data, max(leftInfo->max, rightInfo->max));
  int currSz = leftInfo->sz + rightInfo->sz + 1;

  Info* ans = new Info(isCurrBST, currMin, currMax, currSz);

  // updating maxSz if curr is BST
  if (isCurrBST) maxSz = max(maxSz, ans->sz);  
  return ans;
}

int main(){
  
  Node* root = new Node(50);
  root->left =  new Node(30);
  root->left->left = new Node(5);
  root->left->right = new Node(20);


  root->right = new Node(60);
  root->right->left = new Node(45);
  root->right->right = new Node(70);
  root->right->right->left = new Node(65);
  root->right->right->right = new Node(80);

  largestBST(root);
  cout<<maxSz;
  return 0;
}
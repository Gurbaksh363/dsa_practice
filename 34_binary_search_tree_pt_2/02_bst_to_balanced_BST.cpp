#include <iostream>
#include <vector>
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

Node* BSTFromSortedVec(vector<int>& arr, int start, int end){
  if(start>end) return NULL;

  int mid = start + (end-start)/2;

  Node* curr = new Node(arr[mid]);
  curr->left= BSTFromSortedVec(arr, start, mid-1);
  curr->right= BSTFromSortedVec(arr, mid+1, end);

  return curr;
}

void getInorder(Node* root, vector<int>& seq){
  if(root==NULL) return;
  getInorder(root->left, seq);
  seq.push_back(root->data);
  getInorder(root->right, seq);
}

Node* balancedBST(Node* root){
  // get seq
  vector<int> seq;
  getInorder(root, seq);
  // inorder seq to bst
  return BSTFromSortedVec(seq, 0, seq.size()-1);
}

void preorder(Node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

int main(){
  
  Node* root = new Node(6);
  root->left =  new Node(5);
  root->left->left = new Node(4);
  root->left->left->left = new Node(3);

  root->right = new Node(7);
  root->right->right = new Node(8);
  root->right->right->right = new Node(9);


  preorder(root); cout<<endl;//  6 5 4 3 7 8 9 
  root = balancedBST(root);
  
  preorder(root); // 6 4 3 5 8 7 9 
  return 0;
}
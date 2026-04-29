#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;

  Node(int data){
    this->data = data;
    left = right = NULL;
  }
};

Node* insert(Node* root, int val){
  if (root == NULL) return root = new Node(val);
  if(val<root->data){
    root->left = insert(root->left, val);
  }else{
    root->right = insert(root->right, val);
  }
  return root;
}
Node* buildBST(int arr[], int n){ // O(n * log n)... not exactly nobody asks cause the tree is growing
  Node* root = NULL;
  for(int i = 0; i<n; i++){
    root = insert(root, arr[i]);
  }
  return root;
}
void inorder(Node* root){
  if(root==NULL) return;
  inorder(root->left);
  cout<<root->data<<" ";
  inorder(root->right);
}

Node* findInorderSuccessor(Node* root){
  while(root->left!=NULL){
    root = root->left;
  }
  return root;
}
Node* delNode(Node* root, int key){
  if(root==NULL){ return NULL;}

  if(key<root->data){
    root->left = delNode(root->left, key);
  }else if(key>root->data){
    root->right = delNode(root->right, key);
  }else{
    // case1: 0 children
    if((root->left==NULL && root->right==NULL)){
      return NULL;
    }
    // case2: 1 child
    else if(root->left == NULL || root->right ==NULL){
      return root->left==NULL? root->right:root->left;
    }
    // case 3: 2 children
    else{
      // a) find 'inorder successor' and replace its value with curr-root
      // b) and del 'inorder successor' 
      Node* ios = findInorderSuccessor(root->right);
      root->data = ios->data;
      root->right =  delNode(root->right, ios->data);
      return root;
    }
  }
  return root;
}

int main(){
   int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

  Node* root = buildBST(arr, 9);
  inorder(root); cout<<endl;

  // root = delNode(root, 4);
  // root = delNode(root, 10);
  root = delNode(root, 5);
  inorder(root); cout<<endl;

  return 0;
}
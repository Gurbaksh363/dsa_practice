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
bool searchBST(Node* root, int key){ // O(height) => avg O(log n) worst cast O(n)
  if (root==NULL) return false;
  if (root->data==key) return true;
  if(key<root->data){
    return searchBST(root->left,key);
  }else{
    return searchBST(root->right,key);
  }
  
}
int main(){
  int arr[6] = {5, 1, 3, 4, 2, 7};

  Node* root = buildBST(arr, 6);
  inorder(root); cout<<endl;

  cout<<searchBST(root, 3)<<endl;  
  cout<<searchBST(root, 100);    

  return 0;
}
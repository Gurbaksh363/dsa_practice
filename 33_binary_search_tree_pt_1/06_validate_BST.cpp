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

bool validateHelper(Node* root, Node* min, Node* max){  // we are using int min max because of the edge cases where INT_MIN is a node
  if(root==NULL) return true;
  if(min!=NULL && root->data<=min->data){
    return false;
  }
  if(max!=NULL && root->data>=max->data){
    return false;
  }

  // bool isLeftValid = validateHelper(root->left, min, root);
  // if(!isLeftValid) return false;
  // return validateHelper(root->right, root , max);
  return validateHelper(root->left, min, root) && validateHelper(root->right, root, max);
}
bool validateBST(Node* root){
  return validateHelper(root, NULL, NULL);
}
int main(){
   int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};
   Node* root = new Node(3);
   root->left = new Node(2);
   root->left->left = new Node(1);
   root->left->right = new Node(4);
   root->right = new Node(5);

  Node* root2 = buildBST(arr, 9);
  cout<<validateBST(root2); 
  cout<<endl;
  cout<<validateBST(root);
  return 0;
}
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
void printPath(vector<int>path){
  for(int node: path){
      cout<<node<<" ";
    }
    cout<<endl;
}
void printRootToLeafHelper(Node* root, vector<int>& path){
  if(root==NULL){
    return;
  }
  // add path
  path.push_back(root->data);
  // printing
  if(root->left==NULL && root->right==NULL){
    printPath(path);
    path.pop_back();
    return;
  }
  printRootToLeafHelper(root->left, path);
  printRootToLeafHelper(root->right, path);
  // remove from path
  path.pop_back();
}
void printRootToLeafPaths(Node* root){
  vector<int> path;
  printRootToLeafHelper(root, path);
}

int main(){
   int arr[9] = {8, 5, 3, 1, 4, 6, 10, 11, 14};

  Node* root = buildBST(arr, 9);
  printRootToLeafPaths(root);

  return 0;
}
#include <iostream>
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

Node* buildBSTHelper(int arr[], int start, int end){
  if(start>end) return NULL;

  int mid = start + (end-start)/2;

  Node* curr = new Node(arr[mid]);
  curr->left= buildBSTHelper(arr, start, mid-1);
  curr->right= buildBSTHelper(arr, mid+1, end);

  return curr;
}

Node* buildBSTFromSorted(int arr[], int n){
  return buildBSTHelper(arr, 0, n-1);
} 
void preorder(Node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}

int main(){
  int arr[7] = {3, 4, 5, 6, 7, 8, 9};
  Node* root = buildBSTFromSorted(arr, 7);
  preorder(root);
  return 0;
}
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
vector<int> mergeSorted(vector<int>& arr1, vector<int>& arr2){
  vector<int>merge;
  int i = 0;
  int j = 0;
  while(i<arr1.size() && j<arr2.size()){
    if(arr1[i]<=arr2[j]){
      merge.push_back(arr1[i++]);
    }else{
      merge.push_back(arr2[j++]);
    }
  }
  while(i<arr1.size()){
    merge.push_back(arr1[i++]);
  }
  while(j<arr1.size()){
    merge.push_back(arr2[j++]);
  }
  return merge;
}

void getInorder(Node* root, vector<int>&ans){
  if (root==NULL) return;
  getInorder(root->left, ans);
  ans.push_back(root->data);
  getInorder(root->right, ans);
}

Node* BSTFromSortedVec(vector<int>& arr, int start, int end){
  if(start>end) return NULL;

  int mid = start + (end-start)/2;

  Node* curr = new Node(arr[mid]);
  curr->left= BSTFromSortedVec(arr, start, mid-1);
  curr->right= BSTFromSortedVec(arr, mid+1, end);

  return curr;
}

void preorder(Node* root){
  if(root==NULL) return;
  cout<<root->data<<" ";
  preorder(root->left);
  preorder(root->right);
}
Node* mergeBSTs(Node* root1, Node* root2){
  vector<int>seq1;
  vector<int>seq2;
  getInorder(root1, seq1);
  getInorder(root2, seq2);

  vector<int>ans = mergeSorted(seq1, seq2);
  return BSTFromSortedVec(ans, 0, ans.size()-1);

}
int main(){
  Node* root1 = new Node(2);
  root1->left = new Node(1);
  root1->right = new Node(4);

  Node* root2 = new Node(9);
  root2->left = new Node(3);
  root2->right = new Node(12);

  Node* root3 = mergeBSTs(root1, root2);
  preorder(root3);
  return 0;
}
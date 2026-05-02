// Question 2: We have a binary search tree and a target node K. The task is to find the
// node with minimum absolute difference with given target value K.
// Examples:
//       8
//     /   \
//     5     11
//   /  \     \
//  3    6     20
// Input 1: K = 5
// Output 1: ans = 5 (abs diff = 0)
// Input 2: K = 19
// Output 2: ans =20 (abs diff = 1)

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
void minAbsHelper(Node* root, int& minDiff, int& node, int k){
    if(root==NULL){
      return ;
    }
    if(abs(root->data-k)<minDiff) {
      minDiff = abs(root->data - k);
      node = root->data;
    }
    minAbsHelper(root->left, minDiff, node, k);
    minAbsHelper(root->right, minDiff, node, k);
}
int minAbsDiff(Node* root, int k){
  int minDiff = INT_MAX;
  int node = -1;
  minAbsHelper(root, minDiff, node,  k);
  return node;
}
int main(){
  Node* root = new Node(8);
  root->left = new Node(5);
  root->left->left = new Node(3);
  root->left->right = new Node(6);

  root->right = new Node(11);
  root->right->right = new Node(20);

  cout<<minAbsDiff(root, 5)<<endl;  // 5
  cout<<minAbsDiff(root, 19)<<endl;  // 20


  return 0;
}
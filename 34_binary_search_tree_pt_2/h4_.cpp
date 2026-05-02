// Question 4: Given two binary search trees, return True if and only if there is a node in
// the first tree and a node in the second tree whose values sum up to a given integer
// target.

// Examples:
//     5
//    / \
//   3   7
//  /\   /\
// 2 4  6  8

//       10
//     /   \
//    6     15
//   / \    / \
//  3  8   11 18

// x = 16 (Target)

// Output: ans = 3, The pairs are: (5, 11), (6, 10) and (8, 8)
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
bool search(int val, Node* root, int target){
  if(root==NULL) return false;
  if(root->data + val ==target) return true;
  if(root->data + val < target) {
    return search(val, root->right, target);
  }else{
    return search(val, root->left, target);
  }
}
// we are iterating root1 and searching it in root2
bool isPresentSum(Node* root1, Node* root2, int target){
  if(root1==NULL) return false;
  return search(root1->data, root2, target) ||  isPresentSum(root1->left, root2, target) ||
   isPresentSum(root1->right, root2, target );
}
int main(){
  // First BST
  Node* root1 = new Node(5);
  root1->left = new Node(3);
  root1->left->left = new Node(2);
  root1->left->right = new Node(4);

  root1->right = new Node(7);
  root1->right->left = new Node(6);
  root1->right->right = new Node(8);

  // Second BST
  Node* root2 = new Node(10);
  root2->left = new Node(6);
  root2->left->left = new Node(3);
  root2->left->right = new Node(8);

  root2->right = new Node(15);
  root2->right->left = new Node(11);
  root2->right->right = new Node(18);

  int target = 16;
  cout<<isPresentSum(root1, root2, target);

 
  return 0;
}
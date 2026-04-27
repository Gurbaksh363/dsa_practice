#include <iostream>
#include <vector>
// #include <pair>
using namespace std;

class Node{
  public:
  int data;
  Node* left;
  Node* right;
  Node(int data){
    this->data = data;
    this->left = NULL;
    this->right = NULL;
  }
};

static int idx =  -1;

Node* buildTree(vector<int>& nodes){
  idx++;
  // base case
  if (nodes[idx] == -1){
    return NULL;
  }

  Node* currNode = new Node(nodes[idx]); // work
  currNode->left = buildTree(nodes); // we have faith it will create left subtree
  currNode->right = buildTree(nodes); // we have faith it will create right subtree

  return currNode;     // we are returning to access the tree

}

int height(Node* root){
  if (root==NULL){
    return 0;
  }
  int leftHt = height(root->left);
  int rightHt = height(root->right);
  return 1 +  max(leftHt,rightHt);
}

// no. of nodes in the longest path btw two leaves
int diam1(Node* root){ // O(n*n);
  if (root==NULL){
    return 0;
  }
  int currDiam = 1 + height(root->left)+height(root->right);
  int leftDiam = diam1(root->left);
  int rightDiam = diam1(root->right);

  return max(currDiam, max (leftDiam, rightDiam));
}

// first is diameter , second is height
pair<int, int> diam2(Node* root){   // O(n)
  if (root ==NULL){
    return make_pair(0,0);
  }
  pair<int,int> leftInfo = diam2(root->left);
  pair<int, int> rightInfo = diam2(root->right);
  
  int leftdiam = leftInfo.first; 
  int rightdiam = leftInfo.first;
  int leftht = leftInfo.second;
  int rightht = leftInfo.second;

  int diam = max(1+leftht+rightht, max(leftdiam, rightdiam)); // max(currdia, leftdia, rightdia)
  int height = 1 + max(leftht, rightht);
  return make_pair(diam, height); ;
  
}
int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);
  
  cout<<"Diameter of the tree is: "<<diam1(root)<<endl; // 21

  pair<int, int> ans = diam2(root);
  cout<<"Diameter = "<<ans.first<<" and ht =  "<<ans.second; //  21 & 3
  return 0;
}
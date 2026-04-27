#include <iostream>
#include <vector>
#include <queue>
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

void levelOrder2(Node* root){
  if (root==NULL){
    return;
  } 
  queue<Node*> Q;
  Q.push(root); 
  Q.push(NULL);
  while(!Q.empty()){
    Node* curr = Q.front();
    Q.pop();
    if(curr==NULL){
      cout<<endl;
      if (Q.empty()){
        break;
      }
      Q.push(NULL);
    }
    else{
        cout<< curr->data<<" ";
        if(curr->left !=NULL){
          Q.push(curr->left);
        }
        if(curr->right!=NULL){
          Q.push(curr->right);
        }
     } 
  }
}


int transform(Node* root){ // return sum of root
  if (root==NULL){
    return 0;
  }
  int preserve = root->data;
  int leftSum = transform(root->left); 
  int rightSum = transform(root->right);
  root->data = leftSum + rightSum;
  return preserve + leftSum + rightSum;
}


int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);
  
  levelOrder2(root);cout<<endl;
  transform(root);
  levelOrder2(root);
  return 0;
}
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

void levelOrder(Node* root){
  if (root==NULL){
    return;
  }

  // create queue to track order of nodes 
  queue<Node*> q;
  q.push(root);  // queue now=> [root]

  while(!q.empty()){
    // accessing node
    Node* curr = q.front();
    q.pop();

    // work on node
    cout<< curr->data<<" ";

    // update q
    if(curr->left !=NULL){
      q.push(curr->left);
    }
    if(curr->right!=NULL){
      q.push(curr->right);
    }

  }
  cout<<endl;

}

void levelOrder2(Node* root){
  if (root==NULL){
    return;
  }

  // create queue to track order of nodes 
  queue<Node*> Q;
  Q.push(root);  // queue now=> [root]
  Q.push(NULL);

  while(!Q.empty()){
    // accessing node
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
        // work on node
        cout<< curr->data<<" ";

        // update q
        if(curr->left !=NULL){
          Q.push(curr->left);
        }
        if(curr->right!=NULL){
          Q.push(curr->right);
        }
     } 
  

  }

}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);
  
  levelOrder(root);
  cout<<endl;
  levelOrder2(root);
  return 0;
}
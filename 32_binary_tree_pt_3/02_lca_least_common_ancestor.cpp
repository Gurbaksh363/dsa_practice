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

// approach 1
bool rootToNodePath(Node* root, int n, vector<int>& path){ // O(n)
  if (root==NULL){
    return false;
  }
  path.push_back(root->data);
  if(root->data==n){
    return true;
  }
  bool inLeftSubtree = rootToNodePath (root->left, n, path);
  bool inRightSubtree = rootToNodePath(root->right, n, path);
  if(inLeftSubtree||inRightSubtree){
    return true;
  }
  path.pop_back();
  return false;
}

int LCA(Node* root, int n1, int n2){ // O(n), O(n)
  if(root==NULL){
    return -1;
  }
  vector<int>path1;
  vector<int>path2;
  rootToNodePath(root, n1, path1);
  rootToNodePath(root, n2, path2);
  
  int lca = root->data;
  for(int i=1; i<min(path1.size(), path2.size()); i++){
    if(path1[i]!=path2[i]){
      break;
    }
    lca = path1[i];
  }
  return lca;
}


Node* LCA2(Node* root, int n1, int n2){ // O(n), O(1)
  if(root==NULL){
    return NULL;
  }
  if (root->data == n1 || root->data ==n2){
    return root;
  }
  Node* leftLCA = LCA2(root->left, n1, n2);
  Node* rightLCA = LCA2(root->right, n1, n2);

  if(leftLCA && rightLCA){
    return root;
  }
  // if(leftLCA){
  //   return leftLCA;
  // }
  // if(rightLCA){
  //   return rightLCA;
  // }
  // return NULL;
  return leftLCA == NULL ? rightLCA : leftLCA;
}

int main(){
  vector<int> nodes ={1, 2, 4, -1, -1, 5, -1, -1, 3, -1, 6, -1, -1};
  Node* root = buildTree(nodes);

  cout<<"LCA: "<<" "<<LCA(root, 4, 5)<<endl;
  cout<<"LCA: "<<" "<<LCA(root, 4, 3)<<endl;
  cout<<"LCA: "<<" "<<LCA(root, 3, 6)<<endl;
  
  cout<<"LCA2: "<<" "<<LCA2(root, 4, 5)->data<<endl;
  cout<<"LCA2: "<<" "<<LCA2(root, 4, 3)->data<<endl;
  cout<<"LCA2: "<<" "<<LCA2(root, 3, 6)->data<<endl;
  return 0;
}
#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int val){
    this->data = val;
    this->next = NULL;
  }
};

class List{
  public:
  Node* head;
  Node* tail;
  List(){
    head = NULL;
    tail = NULL;
  }
  void push_front(int val){
    // if empty
    Node* newNode = new Node(val);
    if(head==NULL){
      head = tail = newNode;
      return ;
    }
    // has eles
    newNode->next = head;
    head = newNode;
  }
  void push_back(int val){
    Node* newNode = new Node(val);
    // empty
    if (head==NULL){
      head = tail = newNode;
    }else{
      // has ele
      tail->next = newNode;
      tail = newNode; 
    }
  }
  void pop_front(){
    // if empty
    if (head==NULL){
      cout<<"List is empty\n";
      return;
    }
    // has ele 
    Node* temp = head;
    head = head->next;
    delete temp;
  }
};

void printList(Node* head){
  Node* temp = head;
  while(temp!=NULL){
    cout<<temp->data<<" -> ";
    temp = temp->next;
  }
  cout<<"NULL\n";
}

Node* splitAtMid(Node* head){
  Node* slow = head;
  Node* fast = head;
  Node* prev = NULL;
  while(fast!=NULL && fast->next!=NULL){
    prev = slow;
    slow = slow->next;
    fast = fast->next;
  }
  if(prev!=NULL){
    prev->next = NULL;
  }
  return slow;
}
Node* reverse(Node* head){
  Node* prev = NULL;
  Node* curr = head;
  while(curr!=NULL){
    Node* nextNode = curr->next;
    curr->next = prev;
    prev = curr;
    curr = nextNode;
  }
  return prev; // prev is head of reversed head
}
void zigZag(Node* head){
  Node* rightHead = splitAtMid(head);
  Node* rightHeadRev = reverse(rightHead);
  // alternating merging:  1st head = head; 2nd head = rightHeadRev
  Node* left = head;
  Node* right = rightHeadRev;
  Node* tail = NULL;

  while(left!=NULL && right!=NULL){
    // storing old connectioins
    Node* nextLeft = left->next;
    Node* nextRight = right->next;

    // updating new connections
    left->next = right;
    right->next =nextLeft;

    // updating pointers
    tail = right;
    left = nextLeft;
    right = nextRight;
  }
  if(right!=NULL){
    tail->next = right;
  }
}

int main(){
  List ll;
  ll.push_back(1);
  ll.push_back(2);
  ll.push_back(3);
  ll.push_back(4);
  ll.push_back(5);

  printList(ll.head);
  zigZag(ll.head);
  printList(ll.head);


  return 0;
}
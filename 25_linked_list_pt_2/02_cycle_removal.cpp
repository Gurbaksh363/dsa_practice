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

void removeCycle(Node* head){
  // detect cycle
  Node* slow = head;
  Node* fast = head;
  bool hasCycle = false;
  while(fast!=NULL && fast->next!=NULL){
    slow = slow->next;
    fast = fast->next->next;
    if(slow==fast){
      cout<<"cycle exists\n";
      hasCycle = true;
      break;
    }
  }
  if(!hasCycle){
    cout<<"no cycle\n";
    return;
  }

  // removal
  slow = head;
  if (slow==fast){
    while(fast->next!=slow){
      fast = fast->next;
    }
    fast->next = NULL;
  }
  else{
    Node* prev = fast;
    while(slow!=fast){
      slow = slow->next;
      prev = fast;
      fast = fast->next;
    }
    prev->next = NULL;
  }
  cout<<"cycle removed successfully\n";
}
int main(){
  List ll;
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);

  // creating cycle
  ll.tail->next = ll.head;
  removeCycle(ll.head);
  printList(ll.head);
  return 0;
}
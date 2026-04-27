#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* prev;
  Node* next;

  Node(int val){
    data = val;
    prev = next = NULL;
  }
};

class DoublyList{
  public:
  Node* head;
  Node* tail;

  DoublyList(){
    head = tail = NULL;
  }

  void push_front(int val){
    // empty
    Node* newNode = new Node(val);
    if (head==NULL){
      head = tail = newNode;
    }else{
      // create new connections
      newNode->next = head;
      head->prev = newNode;
      // update head
      head = newNode;
    }
  }
  void push_back(int val){
    Node* newNode = new Node(val);
    // empty
    if(head==NULL){
      head = tail = newNode;
      return;
    }
    // has ele:
    // create connections
    tail->next = newNode;
    newNode->prev = tail;
    // update tail
    tail = newNode;
  }

  void pop_front(){
    // empty
    if (head==NULL){
      cout<<"LL is empty\n";
      return; 
    }
    else{
      // has ele
      Node* temp = head;
      head = head->next;
      if(head!=NULL){
        head->prev = NULL;
      }
      delete temp;
    }
  }
  void pop_back(){
    // empty
    if(head==NULL){
      cout<<"LL is empty\n";
      return;
    }
    // has eles 
    Node* tailPrev = tail->prev;
    tailPrev->next = NULL;
    delete tail;
    tail = tailPrev;
  }

  void printList(){
    Node* temp = head;
    while(temp!=NULL){
      cout<<temp->data<<" <=> ";
      temp = temp->next;
    }
    cout<<"NULL\n";
  }
};
int main(){
  DoublyList dbll;
  dbll.push_front(5);
  dbll.push_front(4);
  dbll.push_front(3);
  dbll.push_front(2);
  dbll.push_front(1);
  
  dbll.printList();

  cout<<"\nPoping front:\n";
  dbll.pop_front();
  dbll.printList();
  
  cout<<"\nPushing 6 and 7:\n";
  dbll.push_back(6);
  dbll.push_back(7);
  dbll.printList();
  
  cout<<"\nPop back:\n";
  dbll.pop_back();
  dbll.printList();
  return 0;
}
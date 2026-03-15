// WAP to delete entire ll

#include <iostream>
using namespace std;

class Node{
  public:
  int data;
  Node* next;

  Node(int data){
    this->data = data;
    this->next = NULL;
  }

  // ~Node(){    // recursion is dangerous
  //   if(next!=NULL){
  //     delete next;
  //     next = NULL;
  //   }
  // }

};
class List{
  Node* head;
  Node* tail;
  public:
  List(){
    this->head = this->tail = NULL;
  }
  void push_front(int val){
    Node* newNode = new Node(val);
    if(head==NULL){
      head = tail = newNode;
    }
    else{
      newNode->next = head;
      head = newNode;
    }
  }

  void printList(){
    Node* temp = head;
    while(temp != NULL){
      cout<<temp->data<<" -> ";
      temp = temp->next;
    }
    cout<<"NULL"<<endl;
  }

  ~List(){
    // if (head!=NULL){
    //   delete head; // head will point to garbage value then
    //   head = NULL;
    // }

    Node* temp = head;
    while(temp!=NULL){
      // cout<<"desctructor: "<<temp->data<<endl;
      Node* nextNode = temp->next;
      delete temp;  // we are deallocating memory not deleting variable temp
      temp = nextNode;
    }
  }
};
int main(){
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList(); // 1 -> 2 -> 3 -> NULL

  return 0;
}
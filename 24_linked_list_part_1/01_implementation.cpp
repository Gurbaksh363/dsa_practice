// definition, push front, push back, print
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
  void printList(){
    Node* temp = head;
    while(temp != NULL){
      cout<<temp->data<<" -> ";
      temp = temp->next;
    }
    cout<<"NULL"<<endl;
  }
};
int main(){
  List ll;
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList(); // 1 -> 2 -> 3 -> NULL

  ll.push_back(4);
  ll.push_back(5); // 1 -> 2 -> 3 -> 4 --> 5 --> NULL
  ll.printList();
  return 0;
}
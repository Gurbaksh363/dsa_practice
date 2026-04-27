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
    if (head==NULL){
      head = tail = newNode;
    }else{
      tail->next = newNode;
      tail = newNode;
    }
  }
  void pop_front(){
    if (head==NULL){
      cout<<"ll is empty"<<endl;
      return;
    }
    Node* temp = head;
    head = head->next;
    delete temp;
  }
  void pop_back(){
    if (head==NULL){
      cout<<"ll is empty"<<endl;
      return ;
    }
    Node* temp = head;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    temp->next = NULL;
    delete tail;
    tail = temp;
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
  
  return 0;
}
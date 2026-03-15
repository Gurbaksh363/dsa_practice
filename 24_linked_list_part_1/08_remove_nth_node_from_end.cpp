// improved version is there
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
  int getSize(){
    int size = 0;
    Node* temp = head;
    while(temp!=NULL){
      temp = temp->next;
      size++;
    }
    return size;
  }
  void removeNthNodeFromEnd(int n){
    int size = getSize();
    // ll is empty
    if (size==0){
      cout<<"ll is empty"<<endl;
      return ;
    }
    // invalid size
    if(n > size){
        cout<<"Invalid n"<<endl;
        return;
    }
    // traverse to (n-1)th node ie. (size-n)th node from front
    // del at head
    if (size-n==0){
      Node* toDel = head;
      // update tail
      if (head==tail) tail = head->next;
      head = head->next;
      delete toDel;
      return;
    }
    
    // del at middle and end
    Node* prev = head;
    for (int i = 1; i<size-n; i++){
      prev = prev->next;
    }
    Node* toDel = prev->next;
    // update tail
    if (tail==toDel) tail = prev;
    prev->next = toDel->next;
    delete toDel;
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
  ll.push_front(5);
  ll.push_front(4);
  ll.push_front(3);
  ll.push_front(2);
  ll.push_front(1);
  ll.printList(); // 1 -> 2 -> 3 -> 4 -> 5 -> NULL
  ll.removeNthNodeFromEnd(5);
  ll.printList(); // 5 -> 4 -> 3 -> 2 -> 1 -> NULL

  return 0;
}



// void removeNthNodeFromEnd(int n){

//     Node* dummy = new Node(0);
//     dummy->next = head;

//     Node* fast = dummy;
//     Node* slow = dummy;

//     // move fast n+1 steps
//     for(int i=0;i<=n;i++){
//         fast = fast->next;
//     }

//     // move both pointers
//     while(fast != NULL){
//         fast = fast->next;
//         slow = slow->next;
//     }

//     Node* toDel = slow->next;
//     slow->next = toDel->next;

//     delete toDel;

//     head = dummy->next;

//     delete dummy;
// }
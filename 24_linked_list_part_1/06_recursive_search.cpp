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
  void insert(int val, int pos){
    // invalid index 
    if (pos<=0){cout<<"Invalid pos"<<endl; return;}
    // front
    if (pos==1){
      push_front(val);
      return;
    }
    Node* newNode = new Node(val);
    Node* temp = head;
    // middle
    for(int i = 1; temp!=NULL && i<pos-1 ; i++){
      temp = temp->next;
    }
    // invalid index
    if(temp==NULL){cout<<"Invalid pos"<<endl; return; };
    newNode->next = temp->next;
    temp->next = newNode;
    // tail updation 
    if (newNode->next == NULL) tail = newNode;
  }
  void pop_front(){
    // A. empty
    if (head==NULL){
      cout<<"ll is empty"<<endl;
      return;
    }
    // B. has ele: 
    // B1. store current_head in temp
    Node* temp = head;
    // B2. update head
    head = head->next;
    // B3. delete temp
    delete temp;
  }
  void pop_back(){
    // A. empty
    if (head==NULL){
      cout<<"ll is empty"<<endl;
      return ;
    }
    // B. has ele
    Node* temp = head;
    while(temp->next->next!=NULL){
      temp = temp->next;
    }
    // B1. second_last_node to null
    temp->next = NULL;
    // B2. delete last_node
    delete tail;
    // B3. update tail
    tail = temp;

  }
  int itr_search(int key){
    // A. empty (return)
    if (head==NULL){
      cout<<"LL is empty"<<endl;
      return -1;
    }

    // B. has ele ( loop and search)
    Node* temp = head;
    int pos = 1;
    while(temp!=NULL){
      if(temp->data == key){
        return pos;
      }
      pos++;
      temp = temp->next;
    }
    return -1;
    
  }
  int rec_search_helper(Node* head, int key){
    // base case: reaching end
    if(head==NULL){
      return -1;
    }
    // checking key and then moving to next
    if(head->data== key){
      return 1;  // 1 represent current pos if head is real_head
    }
    int pos = rec_search_helper(head->next, key);

    if (pos==-1) return -1;
    return 1+pos;
  }
  int rec_search(int key){
    // A. empty (return)
    if (head==NULL){
      cout<<"LL is empty"<<endl;
      return -1;
    }
    return rec_search_helper(head, key);
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

  cout<<"Pos: "<< ll.itr_search(2)<<endl;
  cout<<"Pos: "<< ll.itr_search(33)<<endl<<endl;

  cout<<"Pos: "<< ll.rec_search(2)<<endl;
  cout<<"Pos: "<< ll.rec_search(33)<<endl;
  return 0;
}
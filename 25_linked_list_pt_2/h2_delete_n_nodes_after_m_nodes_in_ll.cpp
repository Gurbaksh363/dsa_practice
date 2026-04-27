// Question 2:
// Delete N Nodes After M Nodes of a Linked List
// We have a linked list and two integers M and N. Traverse the linked list such that you retain M
// nodes then delete next N nodes, continue the same till end of the linked list. Difficulty Level:
// Rookie.

// Sample Input 1 : M=2 N=2 LL: 1->2->3->4->5->6->7->8
// Sample Output 1 : 1->2->5->6

// Sample Input 2 : M=3 N=2 LL: 1->2->3->4->5->6->7->8->9->10
// Sample Output 2 : 1->2->3->6->7->8

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
};
void delNodes(Node* head, int m, int n){
  if (head==NULL) return;
  Node* prev = NULL;
  Node* temp = head;
  int countM = 0;
  int countN = 0;
  while(temp!=NULL){
    countM++;
    if(countM<=m){
      prev = temp;
      temp=temp->next;
    }else{
      countM = 0;
      countN++;
      prev->next = temp->next;
      delete temp;
    
    }
  }
}
int main(){
  int m1 = 2, n1 = 2;
  List ll1;
  ll1.push_front(8);
  ll1.push_front(7);
  ll1.push_front(6);
  ll1.push_front(5);
  ll1.push_front(4);
  ll1.push_front(3);
  ll1.push_front(2);
  ll1.push_front(1);
  ll1.printList();
  delNodes(ll1.head, m1, n1);
  ll1.printList();
  return 0;
}
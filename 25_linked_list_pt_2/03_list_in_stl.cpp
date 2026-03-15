#include<iostream>
#include <list>
#include <iterator>
using namespace std;

void printList(list<int> ll){
  list<int>::iterator itr;      // we create iterator for traversing list<int> called itr
  
  for(itr = ll.begin(); itr!=ll.end(); itr++){  // ll.begin() ==> head ptr and ll.end() ==> tail->next ptr
    cout<< (*itr)<< " -> ";         // basically itr is behaving as pointer but actually itr is an object 
  }
  cout<<"NULL\n";
}

int main(){
  list<int> ll;
  ll.push_front(2);
  ll.push_front(1); // 1 -> 2

  ll.push_back(3); // 1 -> 2 -> 3
  ll.push_back(4); // 1 -> 2 -> 3 -> 4

  printList(ll);

  cout<<ll.front()<<endl;  // accesing value of head
  cout<<ll.back()<<endl;    // accessing value of tail

  ll.pop_front();
  ll.pop_back();

  printList(ll);

  return 0;
}
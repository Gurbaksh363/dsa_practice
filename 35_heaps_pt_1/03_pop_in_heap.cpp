#include <iostream>
#include <vector>
using namespace std;

class Heap{
  vector<int> vec; // CBT

  public:
  void push(int val){
    // step1 // O(1)
    vec.push_back(val);

    // step2  fix heap // O(log n)
    int childIdx = vec.size()-1;
    int parentIdx = (childIdx-1)/2;
    while (parentIdx>=0 && vec[childIdx]>vec[parentIdx]){        // just changing > to < we get min heap
      swap(vec[childIdx], vec[parentIdx]);
      childIdx = parentIdx;
      parentIdx = (childIdx-1)/2;
    }
  }
  void heapify(int i){
    if(i>=vec.size()){     // if vec has 1 element
      return ;
    }
    int l = 2*i+1;
    int r = 2*i+2;

    int maxIdx = i;
    if(l<vec.size() && vec[l]> vec[maxIdx]) maxIdx = l;           // > to < for min heap
    if(r<vec.size() && vec[r]> vec[maxIdx]) maxIdx = r;           // > to < for min heap

    swap(vec[i], vec[maxIdx]);
    if(maxIdx!=i) heapify(maxIdx);    // swapping with child node
  }
  void pop(){
    // step 1: swap (first, last) ele
    swap( vec[0], vec[vec.size()-1]);

    // step2: del last ele 
    vec.pop_back();

    // step3: heapify
    heapify(0);  // O(log n);
    
  }
  int top(){
    return vec[0]; // highest priority element
  }
  int empty(){
    return vec.size()==0;
  }

};
int main(){
  Heap heap;
  heap.push(9);
  heap.push(4);
  heap.push(8);
  heap.push(1);
  heap.push(2);
  heap.push(5);
  while(!heap.empty()){
    cout<<"Top: "<<heap.top()<<endl;
    heap.pop();
  }
  return 0;
}
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
  void pop(){
    
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
  heap.push(50);
  heap.push(10);
  heap.push(100);
  cout<<"Top: "<<heap.top()<<endl;
  return 0;
}
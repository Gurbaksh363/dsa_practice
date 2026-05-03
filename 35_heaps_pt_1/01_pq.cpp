#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(){
  priority_queue<int> pq;
  pq.push(5);
  pq.push(10);
  pq.push(3);
  pq.push(4);
  pq.push(17);

  while(!pq.empty()){
    cout<<"Top: "<<pq.top()<<endl;
    pq.pop();
  }

  priority_queue<string, vector<string>, greater<string>> pq2;
  pq2.push("human");
  pq2.push("apna clg");
  pq2.push("apna ghar");
  pq2.push("c++");
  pq2.push("gk");

  while(!pq2.empty()){
    cout<<"Top: "<<pq2.top()<<endl;
    pq2.pop();
  }
  return 0;
}
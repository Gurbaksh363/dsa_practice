#include <iostream>
#include <queue>
using namespace std;

struct ComparePair{
  bool operator () (pair<string,int> &p1, pair<string, int> &p2){
    return p1.second<p2.second;
  }
};
int main(){
  priority_queue<pair<string, int> , vector<pair<string, int>>, ComparePair> pq;
  pq.push(make_pair("raman", 55));
  pq.push(make_pair("gurbaksh", 75));
  pq.push(make_pair("alia", 35));

  while(!pq.empty()){
    cout<<"Top: "<<pq.top().first<<", "<< pq.top().second<<endl;
    pq.pop();
  }
  return 0;
}
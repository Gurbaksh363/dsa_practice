#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void slidingWindowMax(vector<int> vec, int K){
  priority_queue<pair<int, int>> pq; // maxheap (ele, idx)

  // 1) create maxHeap for 1st window
  for(int i =0; i<K; i++){
    pq.push(make_pair(vec[i], i));
  }
  cout<<pq.top().first<<" ";


  for(int i = K; i<vec.size(); i++){
    while(!pq.empty() && pq.top().second <=i-K){   // removing top elements which are not part of pq
      pq.pop();
    }
    pq.push(make_pair(vec[i], i));  // push new ele in window
    cout<<pq.top().first<< " ";
  }

}
int main(){
  vector<int> vec = {1, 3, -1, -3, 5, 3, 6, 7};
  int K = 3;
  slidingWindowMax(vec, K);
  return 0;
}
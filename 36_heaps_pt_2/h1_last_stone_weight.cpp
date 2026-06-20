// https://leetcode.com/problems/last-stone-weight/
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> pq(stones.begin(), stones.end());// O(n) - shortcut otherwise manual push O(n log n)
         // default - max heap

         while(pq.size()>1){
            int y = pq.top();
            pq.pop();
            int x = pq.top();
            pq.pop();
            if(y!=x){
                pq.push(y-x);
            }
         }
        //  if(pq.empty()) return 0;
        //  return pq.top();
        return pq.empty()? 0: pq.top();

    }
};
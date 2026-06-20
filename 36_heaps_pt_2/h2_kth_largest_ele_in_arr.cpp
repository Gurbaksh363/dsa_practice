// 215. Kth Largest Element in an Array
// https://leetcode.com/problems/kth-largest-element-in-an-array/description/
#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) { // O(n + k log n) -> O(n)
        priority_queue<int> pq(nums.begin(), nums.end()); // O(n) // maxheap

        for(int i = 0; i<k-1; i++){ // O(k log n)
            pq.pop();
        }
        return pq.top();
    }
};
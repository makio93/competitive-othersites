// 解説AC3,優先度キュー1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (int& val : nums) {
            pq.push(val);
            if (pq.size() > (unsigned)k) pq.pop();
        }
        return pq.top();
    }
};

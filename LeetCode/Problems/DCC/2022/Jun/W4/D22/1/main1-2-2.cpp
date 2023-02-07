// 学習1回目,解説2-2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (const int& val : nums) {
            pq.push(val);
            if ((int)(pq.size()) > k) pq.pop();
        }
        return pq.top();
    }
};

// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        int n = stones.size();
        priority_queue<int> pq(stones.begin(), stones.end());
        while ((int)(pq.size()) > 1) {
            int fi = pq.top(); pq.pop();
            int si = pq.top(); pq.pop();
            if (fi - si > 0) pq.push(fi - si);
        }
        return pq.empty() ? 0 : pq.top();
    }
};

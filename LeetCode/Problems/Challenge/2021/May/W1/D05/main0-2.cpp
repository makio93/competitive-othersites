#include <bits/stdc++.h>
using namespace std;

// 自力AC2,メモリ削減

class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.emplace((int)(1e9), n);
        pq.emplace(0, 1);
        for (int i=0; i<n; ++i) {
            while (!pq.empty() && pq.top().second<=i) pq.pop();
            if (i+1 < n) pq.emplace(pq.top().first+1, i+nums[i]+1);
        }
        return pq.top().first;
    }
};

// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n = nums.size();
        unordered_map<int, int> vcnt;
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        auto comp = [&vcnt](int lv, int rv) -> bool { return vcnt[lv] > vcnt[rv]; };
        priority_queue<int, vector<int>, decltype(comp)> pq(comp);
        for (const auto& pi : vcnt) {
            pq.push(pi.first);
            if ((int)(pq.size()) > k) pq.pop();
        }
        vector<int> res;
        while (!pq.empty()) res.push_back(pq.top()), pq.pop();
        return res;
    }
};

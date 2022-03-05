// 自力1,WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int deleteAndEarn(vector<int>& nums) {
        int n = nums.size();
        vector<int> vcnt((int)(1e4)+1);
        for (int i=0; i<n; ++i) vcnt[nums[i]]++;
        priority_queue<pair<int, int>> pq;
        for (int i=1; i<=(int)(1e4); ++i) if (vcnt[i] > 0) pq.emplace(i*vcnt[i], i);
        unordered_set<int> used;
        int res = 0;
        while (!pq.empty()) {
            int val = pq.top().first, num = pq.top().second; pq.pop();
            if (used.find(num) != used.end()) continue;
            res += val;
            for (int di=-1; di<=1; ++di) used.insert(num+di);
        }
        return res;
    }
};

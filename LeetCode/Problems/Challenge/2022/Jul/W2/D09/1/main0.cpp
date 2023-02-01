// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<int, int>> deq;
        deq.emplace_back(0, nums[0]);
        for (int i=1; i<n; ++i) {
            if (deq.front().first == i-k-1) deq.pop_front();
            int val = deq.front().second + nums[i];
            while (!deq.empty() && deq.back().second<=val) deq.pop_back();
            deq.emplace_back(i, val);
        }
        return deq.back().second;
    }
};

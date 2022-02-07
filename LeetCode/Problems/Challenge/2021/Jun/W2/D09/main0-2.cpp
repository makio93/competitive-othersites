#include <bits/stdc++.h>
using namespace std;

// 自力AC2,Time:O(n),pair型

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<pair<int, int>> deq;
        for (int i=0; i<n; ++i) {
            if (i-k-1 >= 0) {
                if (deq.back() == pair<int, int>({ dp[i-k-1], i-k-1, })) deq.pop_back();
                else if (deq.front() == pair<int, int>({ dp[i-k-1], i-k-1, })) deq.pop_front();
            }
            dp[i] = nums[i] + (deq.empty() ? 0 : deq.back().first);
            if (deq.empty()) deq.emplace_back(dp[i], i);
            else if (dp[i] >= deq.back().first) {
                deq.clear();
                deq.emplace_back(dp[i], i);
            }
            else {
                while (!deq.empty() && deq.front().first<=dp[i]) deq.pop_front();
                deq.emplace_front(dp[i], i);
            }
        }
        return dp[n-1];
    }
};

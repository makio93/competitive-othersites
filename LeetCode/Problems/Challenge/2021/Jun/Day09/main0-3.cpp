#include <bits/stdc++.h>
using namespace std;

// 自力AC3,Time:O(n),int型

class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, 0);
        deque<int> deq;
        for (int i=0; i<n; ++i) {
            if (i-k-1 >= 0) {
                if (deq.back() == dp[i-k-1]) deq.pop_back();
                else if (deq.front() == dp[i-k-1]) deq.pop_front();
            }
            dp[i] = nums[i] + (deq.empty() ? 0 : deq.back());
            if (deq.empty()) deq.push_back(dp[i]);
            else {
                while (!deq.empty() && deq.front()<dp[i]) deq.pop_front();
                deq.push_front(dp[i]);
            }
        }
        return dp[n-1];
    }
};

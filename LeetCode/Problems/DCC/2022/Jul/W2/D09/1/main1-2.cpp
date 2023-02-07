// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -INF);
        deque<int> deq;
        dp[0] = nums[0];
        deq.push_back(0);
        for (int i=1; i<n; ++i) {
            if (deq.front() <= i-k-1) deq.pop_front();
            dp[i] = dp[deq.front()] + nums[i];
            while (!deq.empty() && dp[deq.back()]<=dp[i]) deq.pop_back();
            deq.push_back(i);
        }
        return dp[n-1];
    }
};

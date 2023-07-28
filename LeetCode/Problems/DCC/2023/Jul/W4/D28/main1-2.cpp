// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    bool PredictTheWinner(vector<int>& nums) {
        int n = nums.size();
        vector<vector<int>> memo(n, vector<int>(n, -INF));
        function<int(int, int)> dp = [&](int li, int ri) {
            if (memo[li][ri] != -INF) return memo[li][ri];
            if (li == ri) return memo[li][ri] = nums[li];
            else return memo[li][ri] = max(nums[li] - dp(li+1, ri), nums[ri] - dp(li, ri-1));
        };
        return dp(0, n-1) >= 0;
    }
};

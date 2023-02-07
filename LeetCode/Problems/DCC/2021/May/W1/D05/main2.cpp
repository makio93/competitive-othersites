#include <bits/stdc++.h>
using namespace std;

// 解説AC2,DP,O(n^2)

const int INF = (int)(1e9);
class Solution {
public:
    int jump(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        dp[n-1] = 0;
        for (int i=n-2; i>=0; --i) {
            for (int j=1; j<=nums[i]; ++j) {
                if (i+j >= n) break;
                dp[i] = min(dp[i], dp[i+j]+1);
            }
        }
        return dp[0];
    }
};

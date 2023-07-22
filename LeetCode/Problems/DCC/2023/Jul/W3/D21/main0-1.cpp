// 自力AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const int INF = (int)(1e9);
class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, INF);
        vector<ll> vcnt(n+1, 0);
        vcnt[0] = 1;
        for (int i=0; i<n; ++i) {
            int id = lower_bound(dp.begin(), dp.end(), nums[i]) - dp.begin();
            dp[id] = nums[i];
            vcnt[id+1] += vcnt[id];
        }
        int len = 0;
        for (int i=1; i<n; ++i) {
            if (dp[i] == INF) break;
            ++len;
        }
        return (int)(vcnt[len+1]);
    }
};

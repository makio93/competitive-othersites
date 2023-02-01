// 本番WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
    const int INF = (int)(1e9);
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        vector<int> ans(n), dp(n, INF);
        for (int i=n-1; i>=0; --i) {
            int d = lower_bound(dp.begin(), dp.end(), -heights[i]) - dp.begin();
            int d2 = lower_bound(dp.begin(), dp.end(), INF) - dp.begin();
            ans[i] = d2 - d + 1;
            dp[d] = -heights[i];
        }
        return ans;
    }
};

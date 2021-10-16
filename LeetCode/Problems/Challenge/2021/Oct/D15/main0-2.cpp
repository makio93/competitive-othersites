#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
    int INF = (int)(1e9);
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if (n <= 1) return 0;
        vector<int> sub(n);
        for (int i=1; i<n; ++i) sub[i] = prices[i] - prices[i-1];
        set<int> sid({0}), tid({n-1});
        for (int i=1; i<n; ++i) if (sub[i]>=0 && sub[i-1]<0) { sid.insert(i-1); sid.insert(i); }
        for (int i=1; i<n-1; ++i) if (sub[i]>=0 && sub[i+1]<0) { tid.insert(i-1); tid.insert(i); }
        vector<vector<int>> dp(n, vector<int>(2, -INF));
        dp[0][0] = 0;
        for (int i=1; i<n; ++i) {
            dp[i][0] = max(dp[i-1][0], dp[i-1][1]);
            if (tid.find(i) != tid.end()) {
                auto itr = sid.upper_bound(i-1);
                if (itr != sid.begin()) {
                    int scnt = 0;
                    while (itr!=sid.begin() && scnt<6) {
                        --itr; ++scnt;
                        int si = *itr;
                        dp[i][1] = max(dp[i][1], dp[max(0,si-1)][0]+(prices[i]-prices[si]));
                    }
                }
            }
        }
        return max(dp[n-1][0], dp[n-1][1]);
    }
};

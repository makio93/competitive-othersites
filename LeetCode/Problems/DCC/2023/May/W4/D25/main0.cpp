// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        int rlim = max(n, k) + 1;
        vector<double> dp(rlim+1);
        dp[0] = 1.0;
        dp[1] = -1.0;
        for (int i=0; i<k; ++i) {
            int li = i + 1, ri = min(rlim, i+maxPts+1);
            dp[li] += dp[i] / maxPts;
            dp[ri] -= dp[i] / maxPts;
            dp[i+1] += dp[i];
        }
        double res = 0.0;
        for (int i=k; i<=n; ++i) {
            res += dp[i];
            dp[i+1] += dp[i];
        }
        return res;
    }
};

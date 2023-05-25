// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    double new21Game(int n, int k, int maxPts) {
        vector<double> dp(n+1);
        double sum = k > 0 ? 1.0 : 0.0;
        dp[0] = 1.0;
        for (int i=1; i<=n; ++i) {
            dp[i] = sum / maxPts;
            if (i < k) sum += dp[i];
            if (i-maxPts >= 0 && i-maxPts < k) sum -= dp[i-maxPts];
        }
        return accumulate(dp.begin()+k, dp.begin()+n+1, 0.0);
    }
};

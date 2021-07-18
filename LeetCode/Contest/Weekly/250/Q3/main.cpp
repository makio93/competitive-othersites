#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long maxPoints(vector<vector<int>>& points) {
        int n = points.size(), m = points.front().size();
        vector<vector<long long>> dp(n+1, vector<long long>(m, (long long)(-1e18)));
        dp[0] = vector<long long>(m);
        for (int i=0; i<n; ++i) {
            long long lval = (long long)(-1e18), rval = (long long)(-1e18);
            for (int j=0; j<m; ++j) {
                lval = max(lval, dp[i][j]);
                dp[i+1][j] = max(dp[i+1][j], lval+points[i][j]);
                --lval;
            }
            for (int j=m-1; j>=0; --j) {
                rval = max(rval, dp[i][j]);
                dp[i+1][j] = max(dp[i+1][j], rval+points[i][j]);
                --rval;
            }
        }
        long long res = (long long)(-1e18);
        for (int i=0; i<m; ++i) res = max(res, dp[n][i]);
        return res;
    }
};

int main() {
    
    return 0;
}

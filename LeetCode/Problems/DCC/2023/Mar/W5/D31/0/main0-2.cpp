// 自力AC2

#include <bits/stdc++.h>
using namespace std;

const long long mod = (long long)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int r = pizza.size(), c = pizza[0].length();
        vector dp(r, vector(c, vector(k, 0LL)));
        vector sum(r+1, vector(c+1, 0));
        for (int i=r-1; i>=0; --i) for (int j=c-1; j>=0; --j) {
            sum[i][j] = pizza[i][j] == 'A' ? 1 : 0;
            sum[i][j] += sum[i+1][j] + sum[i][j+1] - sum[i+1][j+1];
            if (sum[i][j] > 0) dp[i][j][0] = 1;
            for (int i2=1; i2<k; ++i2) {
                auto& tdp = dp[i][j][i2];
                for (int j2=j+1; j2<c; ++j2) if (sum[i][j]-sum[i][j2] > 0) tdp = (tdp + dp[i][j2][i2-1]) % mod;
                for (int j2=i+1; j2<r; ++j2) if (sum[i][j]-sum[j2][j] > 0) tdp = (tdp + dp[j2][j][i2-1]) % mod;
            }
        }
        return (int)dp[0][0][k-1];
    }
};

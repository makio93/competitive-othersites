// 学習2回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza.front().length();
        vector<vector<int>> asum(rows+1, vector<int>(cols+1));
        for (int i=rows-1; i>=0; --i) for (int j=cols-1; j>=0; --j) asum[i][j] = asum[i+1][j] + asum[i][j+1] - asum[i+1][j+1] + (pizza[i][j] == 'A' ? 1 : 0);
        vector<vector<vector<ll>>> dp(k, vector<vector<ll>>(rows, vector<ll>(cols)));
        for (int i=rows-1; i>=0; --i) for (int j=cols-1; j>=0; --j) {
            if (asum[i][j] > 0) dp[0][i][j] = 1;
            for (int i2=i+1; i2<rows; ++i2) {
                if (asum[i][j]-asum[i2][j] > 0) for (int j2=1; j2<k; ++j2) dp[j2][i][j] = (dp[j2][i][j] + dp[j2-1][i2][j]) % mod;
            }
            for (int i2=j+1; i2<cols; ++i2) {
                if (asum[i][j]-asum[i][i2] > 0) for (int j2=1; j2<k; ++j2) dp[j2][i][j] = (dp[j2][i][j] + dp[j2-1][i][i2]) % mod;
            }
        }
        return (int)dp[k-1][0][0];
    }
};

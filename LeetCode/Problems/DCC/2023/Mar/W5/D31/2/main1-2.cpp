// 学習2回目,解説AC2

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
        vector<vector<ll>> dp(rows, vector<ll>(cols));
        for (int ki=0; ki<k; ++ki) {
            for (int i=0; i<rows; ++i) for (int j=0; j<cols; ++j) {
                if (ki == 0) {
                    if (asum[i][j] > 0) dp[i][j] = 1;
                }
                else {
                    dp[i][j] = 0;
                    for (int i2=i+1; i2<rows; ++i2) if (asum[i][j]-asum[i2][j] > 0) dp[i][j] = (dp[i][j] + dp[i2][j]) % mod;
                    for (int i2=j+1; i2<cols; ++i2) if (asum[i][j]-asum[i][i2] > 0) dp[i][j] = (dp[i][j] + dp[i][i2]) % mod;
                }
            }
        }
        return (int)dp[0][0];
    }
};

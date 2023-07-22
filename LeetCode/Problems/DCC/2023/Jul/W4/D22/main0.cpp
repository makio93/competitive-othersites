// 自力AC

#include <bits/stdc++.h>
using namespace std;

vector<int> di = { -2, -1, 1, 2, 2, 1, -1, -2 }, dj = { 1, 2, 2, 1, -1, -2, -2, -1 };
class Solution {
public:
    double knightProbability(int n, int k, int row, int column) {
        vector<vector<double>> dp(n, vector<double>(n)), ndp;
        dp[row][column] = 1.0;
        while (k--) {
            ndp.assign(n, vector<double>(n));
            for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) for (int i2=0; i2<8; ++i2) {
                int ni = i + di[i2], nj = j + dj[i2];
                if (ni<0 || ni>=n || nj<0 || nj>=n) continue;
                ndp[ni][nj] += dp[i][j] / 8.0;
            }
            swap(ndp, dp);
        }
        double res = 0.0;
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) res += dp[i][j];
        return res;
    }
};

// 解説AC1

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int r = pizza.size(), c = pizza[0].length();
        vector dp(k, vector(r, vector(c, 0)));
        vector app(r+1, vector(c+1, 0));
        for (int i=r-1; i>=0; --i) for (int j=c-1; j>=0; --j) {
            app[i][j] = (pizza[i][j] == 'A') + app[i+1][j] + app[i][j+1] - app[i+1][j+1];
            dp[0][i][j] = app[i][j] > 0;
        }
        for (int ki=1; ki<k; ++ki) for (int i=r-1; i>=0; --i) for (int j=c-1; j>=0; --j) {
            for (int i2=1; r-i2>i; ++i2) if (app[i][j]-app[r-i2][j] > 0) (dp[ki][i][j] += dp[ki-1][r-i2][j]) %= mod;
            for (int i2=1; c-i2>j; ++i2) if (app[i][j]-app[i][c-i2] > 0) (dp[ki][i][j] += dp[ki-1][i][c-i2]) %= mod;
        }
        return dp[k-1][0][0];
    }
};

// 解説AC2

#include <bits/stdc++.h>
using namespace std;

const int mod = (int)(1e9) + 7;
class Solution {
public:
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        int res = 0;
        vector<vector<int>> dp(m, vector<int>(n)), ndp;
        dp[startRow][startColumn] = 1;
        while (maxMove--) {
            ndp.assign(m, vector<int>(n));
            for (int y=0; y<m; ++y) for (int x=0; x<n; ++x) {
                if (y-1 < 0) res = (res + dp[y][x]) % mod;
                if (y+1 >= m) res = (res + dp[y][x]) % mod;
                if (x-1 < 0) res = (res + dp[y][x]) % mod;
                if (x+1 >= n) res = (res + dp[y][x]) % mod;
                ndp[y][x] = (((y-1 >= 0 ? dp[y-1][x] : 0) + (y+1 < m ? dp[y+1][x] : 0)) % mod +
                    ((x-1 >= 0 ? dp[y][x-1] : 0) + (x+1 < n ? dp[y][x+1] : 0)) % mod) % mod;
            }
            swap(ndp, dp);
        }
        return res;
    }
};

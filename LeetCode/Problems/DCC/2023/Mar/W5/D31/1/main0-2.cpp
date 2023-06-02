// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza.front().length();
        vector dp(rows+1, vector(cols+1, vector(k+1, 0LL)));
        function<bool(int,int,int,int)> is_apples = [&](int row, int col, int max_row, int max_col) {
            for (int ri=row; ri<max_row; ++ri) for (int ci=col; ci<max_col; ++ci) if (pizza[ri][ci] == 'A') return true;
            return false;
        };
        for (int ri=rows; ri>=0; --ri) for (int ci=cols; ci>=0; --ci) for (int ki=0; ki<=k; ++ki) {
            if (ri==rows || ci==cols) { if (ki == 0) dp[ri][ci][ki] = 1; }
            else {
                if (ki == 1) { if (is_apples(ri, ci, rows, cols)) dp[ri][ci][ki] = 1; }
                else if (ki > 1) {
                    for (int tri=ri+1; tri<rows; ++tri) if (is_apples(ri, ci, tri, cols)) dp[ri][ci][ki] = (dp[ri][ci][ki] + dp[tri][ci][ki-1]) % mod;
                    for (int tci=ci+1; tci<cols; ++tci) if (is_apples(ri, ci, rows, tci)) dp[ri][ci][ki] = (dp[ri][ci][ki] + dp[ri][tci][ki-1]) % mod;
                }
            }
        }
        return (int)dp[0][0][k];

    }
};

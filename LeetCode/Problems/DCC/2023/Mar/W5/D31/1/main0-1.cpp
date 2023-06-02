// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza.front().length();
        vector memo(rows+1, vector(cols+1, vector(k+1, -1LL)));
        function<bool(int,int,int,int)> is_apple = [&](int row, int col, int max_row, int max_col) {
            for (int ri=row; ri<max_row; ++ri) for (int ci=col; ci<max_col; ++ci) if (pizza[ri][ci] == 'A') return true;
            return false;
        };
        function<ll(int,int,int)> dp = [&](int row, int col, int ki) {
            if (memo[row][col][ki] != -1) return memo[row][col][ki];
            if (ki == 1) return memo[row][col][ki] = is_apple(row, col, rows, cols) ? 1 : 0;
            ll rval = 0;
            for (int ri=row+1; ri<rows; ++ri) {
                if (!is_apple(row, col, ri, cols)) continue;
                rval = (rval + dp(ri, col, ki-1)) % mod;
            }
            for (int ci=col+1; ci<cols; ++ci) {
                if (!is_apple(row, col, rows, ci)) continue;
                rval = (rval + dp(row, ci, ki-1)) % mod;
            }
            return memo[row][col][ki] = rval;
        };
        return (int)dp(0, 0, k);
    }
};

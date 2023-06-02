// 自力AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int ways(vector<string>& pizza, int k) {
        int rows = pizza.size(), cols = pizza[0].length();
        vector memo(rows, vector(cols, vector(k, -1LL)));
        auto acnt = [&](int ri, int ci) -> int {
            int rcnt = 0;
            for (int i=ri; i<rows; ++i) for (int j=ci; j<cols; ++j) if (pizza[i][j] == 'A') ++rcnt;
            return rcnt;
        };
        auto dfs = [&](auto dfs, int di=0, int ri=0, int ci=0) -> ll {
            if (memo[ri][ci][di] != -1LL) return memo[ri][ci][di];
            int aval = acnt(ri, ci);
            if (di == k-1) return memo[ri][ci][di] = (aval > 0) ? 1 : 0;
            if (ri==rows-1 && ci==cols-1) return memo[ri][ci][di] = 0;
            ll rval = 0;
            for (int tri=ri+1; tri<rows; ++tri) if (aval > acnt(tri, ci)) rval = (rval + dfs(dfs, di+1, tri, ci)) % mod;
            for (int tci=ci+1; tci<cols; ++tci) if (aval > acnt(ri, tci)) rval = (rval + dfs(dfs, di+1, ri, tci)) % mod;
            return memo[ri][ci][di] = rval;
        };
        return (int)dfs(dfs);
    }
};

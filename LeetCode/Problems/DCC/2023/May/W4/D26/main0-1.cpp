// 自力AC1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();
        vector<vector<vector<int>>> memo(n+1, vector<vector<int>>(n+1, vector<int>(2, -1)));
        function<int(int,int,int)> dfs = [&](int vi, int mi, int ali) {
            mi = min(mi, n-vi);
            if (memo[vi][mi][ali] != -1) return memo[vi][mi][ali];
            if (vi == n) return memo[vi][mi][ali] = 0;
            int ri = min(mi*2, n-vi), rval = (ali == 1 ? 0 : INF), sum = 0;
            for (int i=1; i<=ri; ++i) {
                sum += piles[vi+i-1];
                if (ali == 1) rval = max(rval, dfs(vi+i, max(i, mi), 0) + sum);
                else rval = min(rval, dfs(vi+i, max(i, mi), 1));
            }
            return memo[vi][mi][ali] = rval;
        };
        return dfs(0, 1, 1);
    }
};

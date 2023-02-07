#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(-1.1e9);
class Solution {
    vector<int> vals, sums;
    vector<vector<int>> memo;
    int calc(int l, int r) {
        if (memo[l][r] != INF) return memo[l][r];
        bool alice = (((int)(vals.size())-(r-l+1))%2 == 0);
        if (r-l <= 0) return (memo[l][r] = 0);
        else {
            int lval = (alice ? calc(l+1,r)+(sums[r+1]-sums[l+1]) : calc(l+1,r)-(sums[r+1]-sums[l+1]));
            int rval = (alice ? calc(l,r-1)+(sums[r]-sums[l]) : calc(l,r-1)-(sums[r]-sums[l]));
            return (memo[l][r] = (alice ? max(lval,rval) : min(lval,rval)));
        }
    }
public:
    int stoneGameVII(vector<int>& stones) {
        int n = stones.size();
        vals = stones;
        sums = vector<int>(n+1);
        for (int i=0; i<n; ++i) sums[i+1] += sums[i] + vals[i];
        memo = vector<vector<int>>(n, vector<int>(n, INF));
        return calc(0, n-1);
    }
};

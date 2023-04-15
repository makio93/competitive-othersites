// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxValueOfCoins(vector<vector<int>>& piles, int k) {
        int n = piles.size();
        vector dp(n+1, vector(k+1, -1));
        function<int(int, int)> f = [&](int di, int ci) {
            if (dp[di][ci] != -1) return dp[di][ci];
            if (di == 0) return dp[di][ci] = 0;
            int sum = 0, val = 0;
            for (int i=0; i<=min((int)(piles[di-1].size()),ci); ++i) {
                val = max(val, f(di-1,ci-i)+sum);
                if (i < (int)(piles[di-1].size())) sum += piles[di-1][i];
            }
            return dp[di][ci] = val;
        };
        return f(n, k);
    }
};

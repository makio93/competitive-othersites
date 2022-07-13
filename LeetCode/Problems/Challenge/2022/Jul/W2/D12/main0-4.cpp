// 自力AC,ヒント有り

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool makesquare(vector<int>& matchsticks) {
        int n = matchsticks.size();
        int tar = 0;
        for (int val : matchsticks) tar += val;
        if (tar%4 != 0) return false;
        tar /= 4;
        vector<bool> dp(1<<n);
        dp[0] = true;
        for (int i=0; i<1<<n; ++i) if (dp[i]) {
            int sum = 0;
            for (int j=0; j<n; ++j) if ((i>>j)&1) sum += matchsticks[j];
            int ri = sum / tar;
            for (int j=0; j<n; ++j) if (!((i>>j)&1)) {
                int tid = i | (1<<j), nsum = sum + matchsticks[j];
                if ((nsum%tar==0&&nsum/tar==ri+1) || (nsum%tar!=0&&nsum/tar==ri)) dp[tid] = true;
            }
        }
        return dp[(1<<n)-1];
    }
};

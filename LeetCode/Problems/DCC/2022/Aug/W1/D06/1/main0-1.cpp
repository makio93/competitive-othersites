// 学習1回目,自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        int turns = minutesToTest / minutesToDie, bval = 0;
        while (buckets > 1<<bval) ++bval;
        if (bval == 0) return bval;
        vector<vector<int>> dp(bval, vector<int>(turns, 0));
        for (int i=0; i<bval; ++i) for (int j=0; j<turns; ++j) {
            if (j == 0) dp[i][j] = 1 << (i+1);
            else {
                int cval = 1;
                dp[i][j] = 1;
                for (int j2=1; j2<=i+1; ++j2) {
                    cval *= i + 1 - j2 + 1;
                    cval /= j2;
                    dp[i][j] += dp[j2-1][j-1] * cval;
                }
            }
            if (dp[i][j] >= buckets) return i + 1;
        }
        return bval + 1;
    }
};

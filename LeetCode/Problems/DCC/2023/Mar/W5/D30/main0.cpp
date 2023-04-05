// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isScramble(string s1, string s2) {
        int n = s1.length();
        vector dp(n, vector(n+1, vector(n, false)));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) if (s1[i] == s2[j]) dp[i][i+1][j] = true;
        for (int k=2; k<=n; ++k) for (int i=0; i+k<=n; ++i) for (int j=0; j+k<=n; ++j) {
            for (int li=1; li<k; ++li) {
                int ri = k - li;
                if ((dp[i][i+li][j]&&dp[i+li][i+k][j+li]) || (dp[i][i+li][j+ri]&&dp[i+li][i+k][j])) {
                    dp[i][i+k][j] = true;
                    break;
                }
            }
        }
        return dp[0][n][0];
    }
};

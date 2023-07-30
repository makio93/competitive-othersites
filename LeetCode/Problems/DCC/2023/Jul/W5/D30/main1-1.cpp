// 解説AC1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int strangePrinter(string s) {
        int n = s.length();
        vector<vector<int>> dp(n, vector<int>(n, INF));
        for (int i=0; i<n; ++i) {
            for (int li=0; li+i<n; ++li) {
                int ri = li + i, mi = -1;
                for (int j=li; j<ri; ++j) {
                    if (mi == -1 && s[ri] != s[j]) mi = j;
                    if (mi != -1) dp[li][ri] = min(dp[li][ri], dp[mi][j]+1+dp[j+1][ri]);
                }
                if (mi == -1) dp[li][ri] = 0;
            }
        }
        return dp[0][n-1] + 1;
    }
};

#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minCut(string s) {
        int n = s.length();
        vector<vector<int>> palind(n);
        for (int i=0; i<n; ++i) {
            int l = i, r = i;
            while (l>=0 && l<n && r>=0 && r<n && s[l]==s[r]) {
                palind[l].push_back(r+1);
                --l; ++r;
            }
            l = i; r = l+1;
            while (l>=0 && l<n && r>=0 && r<n && s[l]==s[r]) {
                palind[l].push_back(r+1);
                --l; ++r;
            }
        }
        vector<int> dp(n+1, n+1);
        dp[0] = 0;
        for (int i=0; i<n; ++i) if (dp[i] != n+1) {
            for (int j : palind[i]) dp[j] = min(dp[j], dp[i]+1);
        }
        return (dp[n] - 1);
    }
};

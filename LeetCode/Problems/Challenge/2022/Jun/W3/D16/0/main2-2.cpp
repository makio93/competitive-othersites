// 解説AC2-2,メモリ削減

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> dp(3, vector<bool>(n));
        pair<int, int> ids = { 1, 0 };
        for (int i=0; i<n; ++i) dp[1][i] = true;
        for (int i=0; i+1<n; ++i) if (s[i] == s[i+1]) {
            dp[2][i] = true;
            ids = max(ids, { 2, -i });
        }
        for (int i=3; i<=n; ++i) for (int j=0; j+i-1<n; ++j) {
            if (s[j]==s[j+i-1] && dp[(i+1)%3][j+1]) {
                dp[i%3][j] = true;
                ids = max(ids, { i, -j });
            }
            else dp[i%3][j] = false;
        }
        return s.substr(-ids.second, ids.first);
    }
};

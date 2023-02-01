// 本番WA2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(string s, int k) {
        int n = s.length();
        reverse(s.begin(), s.end());
        string t;
        while (k > 0) {
            t.push_back((char)((k%2)+'0'));
            k /= 2;
        }
        if ((int)(t.length()) > n) return n;
        if (s == string(n, '0')) return n;
        while ((int)(t.length()) < n) t.push_back('0');
        vector<vector<bool>> dp(n+1, vector<bool>(2));
        dp[0][0] = true;
        for (int i=0; i<n; ++i) for (int j=n-1; j>=0; --j) {
            if (s[i] == t[j]) {
                if (dp[j][0]) dp[j+1][0] = true;
                if (dp[j][1]) dp[j+1][1] = true;
            }
            else if (s[i]=='0' && t[j]=='1') {
                if (dp[j][0] || dp[j][1]) dp[j+1][0] = true;
            }
            else {
                if (dp[j][0] || dp[j][1]) dp[j+1][1] = true;
            }
        }
        int res = 0;
        for (int i=0; i<=n; ++i) if (dp[i][0]) res = max(res, i);
        return res;
    }
};

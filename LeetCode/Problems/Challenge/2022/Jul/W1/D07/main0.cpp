// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();
        if (m+n != l) return false;
        if (m > n) {
            swap(n, m);
            swap(s1, s2);
        }
        vector<bool> dp(m+1);
        dp[0] = true;
        for (int i=0; i<l; ++i) {
            for (int j=min(i,m); j>=max(0,i-n); --j) {
                if (!dp[j]) continue;
                int i1 = i - j, i2 = j;
                if (i1 < n) {
                    if (s1[i1] == s3[i]) dp[j] = true;
                    else dp[j] = false;
                }
                if (i2 < m) {
                    if (s2[i2] == s3[i]) dp[j+1] = true;
                }
            }
        }
        return dp[m];
    }
};

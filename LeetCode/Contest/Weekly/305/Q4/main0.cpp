// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestIdealString(string s, int k) {
        int n = s.length();
        vector<int> dp(26);
        for (int i=0; i<n; ++i) {
            int li = max(0, (int)(s[i]-'a')-k), ri = min(25, (int)(s[i]-'a')+k);
            int pval = 0;
            for (int j=li; j<=ri; ++j) pval = max(pval, dp[j]);
            dp[s[i]-'a'] = max(dp[s[i]-'a'], pval+1);
        }
        int res = 0;
        for (int i=0; i<26; ++i) res = max(res, dp[i]);
        return res;
    }
};

// 

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(), m = wordDict.size();
        vector<bool> dp(n+1);
        dp[0] = true;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (i-(int)(wordDict[j].length())+1 < 0 || !dp[i-(int)(wordDict[j].length())+1]) continue;
            if (s.substr(i-(int)(wordDict[j].length())+1, wordDict[j].length()) == wordDict[j]) dp[i+1] = true;
        }
        return dp[n];
    }
};

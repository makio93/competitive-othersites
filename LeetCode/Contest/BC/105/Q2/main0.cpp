// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minExtraChar(string s, vector<string>& dictionary) {
        int n = s.length(), m = dictionary.size();
        unordered_set<string> dst(dictionary.begin(), dictionary.end());
        vector<int> dp(n+1, n);
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            dp[i+1] = min(dp[i+1], dp[i]+1);
            for (int j=i; j>=0; --j) if (dst.find(s.substr(j, i-j+1)) != dst.end()) dp[i+1] = min(dp[i+1], dp[j]);
        }
        return dp[n];
    }
};

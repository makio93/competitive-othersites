// 解説AC5

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool wordBreak(string s, vector<string>& wordDict) {
        int n = s.length(), m = wordDict.size(), mlen = 0;
        for (int i=0; i<m; ++i) mlen = max(mlen, (int)(wordDict[i].length()));
        unordered_set<string> st(wordDict.begin(), wordDict.end());
        vector<bool> dp(mlen+2);
        dp[0] = true;
        for (int i=0; i<n; ++i) {
            dp[(i+1)%(mlen+2)] = false;
            for (int j=i; j>=0&&i-j+1<=mlen; --j) {
                if (!dp[j%(mlen+2)]) continue;
                if (st.find(s.substr(j, i-j+1)) != st.end()) {
                    dp[(i+1)%(mlen+2)] = true;
                    break;
                }
            }
        }
        return dp[n%(mlen+2)];
    }
};

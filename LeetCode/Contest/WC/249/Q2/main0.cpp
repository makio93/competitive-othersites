#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n = s.length();
        vector<vector<bool>> lcnt(n+1, vector<bool>(26)), rcnt(n+1, vector<bool>(26));
        for (int i=0; i<n; ++i) {
            lcnt[i+1] = lcnt[i];
            lcnt[i+1][s[i]-'a'] = true;
        }
        for (int i=n-1; i>=0; --i) {
            rcnt[i] = rcnt[i+1];
            rcnt[i][s[i]-'a'] = true;
        }
        vector<vector<bool>> pcnt(26, vector<bool>(26));
        for (int i=1; i<=n-2; ++i) {
            for (int j=0; j<26; ++j) if (lcnt[i][j] && rcnt[i+1][j]) pcnt[s[i]-'a'][j] = true;
        }
        int res = 0;
        for (int i=0; i<26; ++i) for (int j=0; j<26; ++j) if (pcnt[i][j]) ++res;
        return res;
    }
};

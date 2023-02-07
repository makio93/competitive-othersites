#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        int m = s.length(), n = p.length();
        vector<vector<int>> scnt(m+1, vector<int>(26));
        for (int i=0; i<m; ++i) for (int j=0; j<26; ++j) scnt[i+1][j] = scnt[i][j] + (s[i]==(char)('a'+j) ? 1 : 0);
        vector<int> pcnt(26);
        for (int i=0; i<n; ++i) for (int j=0; j<26; ++j) pcnt[j] += (p[i]==(char)('a'+j) ? 1 : 0);
        vector<int> res;
        for (int i=0; i+n-1<m; ++i) {
            bool ok = true;
            for (int j=0; j<26; ++j) if (scnt[i+n][j]-scnt[i][j] != pcnt[j]) ok = false;
            if (ok) res.push_back(i);
        }
        return res;
    }
};

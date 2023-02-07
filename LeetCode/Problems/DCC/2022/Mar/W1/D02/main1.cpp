// 解説1AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        int j = 0;
        for (int i=0; j<m&&i<n; ++i) if (s[j] == t[i]) ++j;
        return j == m;
    }
};

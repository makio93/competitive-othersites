// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length(), id = 0;
        for (int i=0; i<n; ++i) if (s[id] == t[i]) {
            ++id;
            if (id >= m) break;
        }
        return (id == m);
    }
};

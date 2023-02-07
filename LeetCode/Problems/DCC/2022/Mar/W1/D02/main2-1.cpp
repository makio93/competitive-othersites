// 解説2-1AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calc(string& s, string& t, int i, int j) {
        if (i==0 || j==0) return 0;
        else if (s[i-1] == t[j-1]) return 1 + calc(s, t, i-1, j-1);
        else return calc(s, t, i, j-1);
    }
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        return calc(s, t, m, n) == m;
    }
};

// 解説2AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    int calc(string& s, string& t, int i, int j, vector<vector<int>>& memo) {
        if (memo[i][j] != -1) return memo[i][j];
        if (i==0 || j==0) return memo[i][j] = 0;
        else if (s[i-1] == t[j-1]) return memo[i][j] = 1 + calc(s, t, i-1, j-1, memo);
        else return memo[i][j] = calc(s, t, i, j-1, memo);
    }
public:
    bool isSubsequence(string s, string t) {
        int m = s.length(), n = t.length();
        vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
        return calc(s, t, m, n, memo) == m;
    }
};

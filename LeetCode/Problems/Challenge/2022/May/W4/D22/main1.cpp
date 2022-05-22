// 解説AC1-1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countSubstrings(string s) {
        int n = s.length();
        vector<vector<int>> memo(n, vector<int>(n, -1));
        auto dfs = [&](auto dfs, int li, int ri) -> int {
            if (memo[li][ri] != -1) return memo[li][ri];
            if (li >= ri) return memo[li][ri] = 1;
            else return memo[li][ri] = (s[li] == s[ri] ? dfs(dfs, li+1, ri-1) : 0);
        };
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=i; j<n; ++j) res += dfs(dfs, i, j);
        return res;
    }
};

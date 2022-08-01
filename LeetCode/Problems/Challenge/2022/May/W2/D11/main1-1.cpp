// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<vector<int>> memo(n+1, vector<int>(6, -1));
        auto dfs = [&](auto dfs, int vi, int ki) -> int {
            if (memo[vi][ki] != -1) return memo[vi][ki];
            if (ki == 0) return memo[vi][ki] = 0;
            if (vi == 0) return memo[vi][ki] = 1;
            return memo[vi][ki] = dfs(dfs, vi-1, ki) + dfs(dfs, vi, ki-1);
        };
        return dfs(dfs, n, 5);
    }
};

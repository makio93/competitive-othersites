// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.length(), m = s2.length(), l = s3.length();
        if (m+n != l) return false;
        vector<vector<int>> memo(n+1, vector<int>(m+1, -1));
        auto dfs = [&](auto dfs, int id1=0, int id2=0) -> bool {
            if (memo[id1][id2] != -1) return memo[id1][id2] == 1 ? true : false;
            if (id1==n && id2==m) {
                memo[id1][id2] = 1;
                return true;
            }
            bool rval = false;
            if (id1 >= n) rval |= (s2[id2]==s3[id1+id2] && dfs(dfs, id1, id2+1));
            else if (id2 >= m) rval |= (s1[id1]==s3[id1+id2] && dfs(dfs, id1+1, id2));
            else rval |= (s1[id1]==s3[id1+id2] && dfs(dfs, id1+1, id2)) || (s2[id2]==s3[id1+id2] && dfs(dfs, id1, id2+1));
            memo[id1][id2] = rval ? 1 : 0;
            return rval;
        };
        return dfs(dfs);
    }
};

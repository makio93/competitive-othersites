// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combine(int n, int k) {
        vector<vector<int>> res;
        vector<int> vlst;
        function<void(int, int)> dfs = [&](int di, int ri) {
            if (di == k) {
                res.push_back(vlst);
                return;
            }
            if (ri > n) return;
            for (int i=ri; i<=n; ++i) {
                vlst.push_back(i);
                dfs(di+1, i+1);
                vlst.pop_back();
            }
        };
        dfs(0, 1);
        return res;
    }
};

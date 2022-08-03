// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> nlst;
        auto dfs = [&](auto dfs, int val=1) -> void {
            if (nlst.size() == (size_t)k) {
                if (accumulate(nlst.begin(), nlst.end(), 0) == n) res.push_back(nlst);
                return;
            }
            if (val > 9) return;
            nlst.push_back(val);
            dfs(dfs, val+1);
            nlst.pop_back();
            dfs(dfs, val+1);
        };
        dfs(dfs);
        return res;
    }
};

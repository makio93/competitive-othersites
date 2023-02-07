// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> res;
        vector<int> nlst;
        auto dfs = [&](auto dfs, int sum=0) -> void {
            if (sum > n) return;
            if (nlst.size() == (size_t)k) {
                if (sum == n) res.push_back(nlst);
                return;
            }
            int nval = (nlst.empty()) ? 1 : nlst.back() + 1;
            while (nval <= 9) {
                nlst.push_back(nval);
                dfs(dfs, sum+nval);
                nlst.pop_back();
                ++nval;
            }
        };
        dfs(dfs);
        return res;
    }
};

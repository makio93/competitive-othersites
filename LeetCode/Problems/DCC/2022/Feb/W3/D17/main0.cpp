// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        int n = candidates.size();
        vector<vector<int>> res;
        vector<int> rlst;
        function<void(int,int)> dfs = [&](int d, int val) -> void {
            if (val > target) return;
            if (val == target) {
                res.push_back(rlst);
                return;
            }
            if (d >= n) return;
            int vcnt = 0;
            do {
                dfs(d+1, val);
                rlst.push_back(candidates[d]);
                val += candidates[d];
                ++vcnt;
            } while (val <= target);
            rlst.erase(rlst.end()-vcnt, rlst.end());
            val -= candidates[d] * vcnt;
        };
        dfs(0, 0);
        return res;
    }
};

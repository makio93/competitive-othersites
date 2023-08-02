// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permute(vector<int>& nums) {
        int n = nums.size();
        vector<bool> used(n);
        vector<int> perm(n, -1);
        vector<vector<int>> res;
        function<void(int)> dfs = [&](int vi) {
            if (vi == n) res.push_back(perm);
            else {
                for (int i=0; i<n; ++i) if (!used[i]) {
                    used[i] = true;
                    perm[vi] = nums[i];
                    dfs(vi+1);
                    used[i] = false;
                    perm[vi] = -1;
                }
            }
        };
        dfs(0);
        return res;
    }
};

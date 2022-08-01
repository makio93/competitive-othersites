// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<pair<int, int>> vcnts;
        for (int i=0; i<n; ++i) {
            if (vcnts.empty() || vcnts.back().first!=nums[i]) vcnts.emplace_back(nums[i], 1);
            else vcnts.back().second++;
        }
        vector<vector<int>> res;
        int m = vcnts.size();
        vector<int> per(n);
        function<void(int)> dfs = [&](int di) {
            if (di == n) {
                res.push_back(per);
                return;
            }
            for (int i=0; i<m; ++i) if (vcnts[i].second > 0) {
                per[di] = vcnts[i].first;
                vcnts[i].second--;
                dfs(di+1);
                vcnts[i].second++;
            }
        };
        dfs(0);
        return res;
    }
};

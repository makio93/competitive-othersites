#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        int n = nums.size();
        set<vector<int>> vecset;
        for (int i=0; i<(1<<n); ++i) {
            vector<int> vec;
            for (int j=0; j<n; ++j) if ((i>>j)&1) vec.push_back(nums[j]);
            sort(vec.begin(), vec.end());
            vecset.insert(vec);
        }
        vector<vector<int>> res;
        for (auto vi : vecset) res.push_back(vi);
        return res;
    }
};

#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    vector<int> largestDivisibleSubset(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        unordered_map<int, set<int>> slst;
        for (int i=0; i<n; ++i) {
            slst[nums[i]].insert(nums[i]);
            for (auto& pi : slst) if (pi.first!=nums[i] && nums[i]%pi.first==0) {
                if (slst[nums[i]].size() < pi.second.size()+1) {
                    slst[nums[i]] = pi.second;
                    slst[nums[i]].insert(nums[i]);
                }
            }
        }
        pair<int, int> mval = { 0, -1 };
        for (auto pi : slst) mval = max(mval, { pi.second.size(), -pi.first });
        vector<int> res(slst[-mval.second].begin(), slst[-mval.second].end());
        return res;
    }
};

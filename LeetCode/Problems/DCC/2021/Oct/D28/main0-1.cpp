#include <bits/stdc++.h>
using namespace std;

// 自力AC1,解法1,O(N*NlogN)解法

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> lvals;
        unordered_set<int> rvals;
        for (int i=0; i<n; ++i) lvals[nums[i]]++;
        set<vector<int>> rlst;
        for (int i=n-1; i>=0; --i) {
            lvals[nums[i]]--;
            if (lvals[nums[i]] == 0) lvals.erase(nums[i]);
            vector<int> lst = { nums[i] };
            for (auto val : lvals) if (rvals.find(-(val.first+nums[i])) != rvals.end()) {
                auto tlst = lst;
                tlst.push_back(val.first);
                tlst.push_back(-(val.first+nums[i]));
                sort(tlst.begin(), tlst.end());
                rlst.insert(tlst);
            }
            rvals.insert(nums[i]);
        }
        vector<vector<int>> res(rlst.begin(), rlst.end());
        return res;
    }
};

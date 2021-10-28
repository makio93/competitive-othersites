#include <bits/stdc++.h>
using namespace std;

// 自力AC2,解法2,改良,計算量同じ

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int nlen = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> vals;
        for (int i=0; i<nlen; ++i) {
            if ((nums[i]!=0&&(i-2<0||(i-2>=0&&nums[i]!=nums[i-2]))) || 
                (nums[i]==0&&(i-3<0||(i-3>=0&&nums[i]!=nums[i-3])))) vals.push_back(nums[i]);
        }
        int n = vals.size();
        vector<vector<int>> res;
        for (int i=1; i<n-1; ++i) for (int j=0; j<i; ++j) {
            int k = lower_bound(vals.begin()+(i+1), vals.end(), -(vals[i]+vals[j])) - vals.begin();
            if (k<n && vals[k]==-(vals[i]+vals[j])) res.push_back({vals[j], vals[i], vals[k]});
        }
        sort(res.begin(), res.end());
        res.erase(unique(res.begin(), res.end()), res.end());
        return res;
    }
};

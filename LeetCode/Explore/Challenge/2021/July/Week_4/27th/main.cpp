#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        pair<int, int> mval = { (int)(1e9), (int)(1e9) };
        for (int i=0; i<n; ++i) for (int j=i+1; j<n; ++j) {
            int tsum = nums[i]+nums[j];
            auto ritr = upper_bound(nums.begin()+(j+1), nums.end(), target-tsum);
            if (ritr != nums.end()) mval = min(mval, { abs(tsum+(*ritr)-target), (tsum+(*ritr)) });
            if (ritr > nums.begin()+j+1) mval = min(mval, { abs(tsum+(*prev(ritr))-target), (tsum+(*prev(ritr))) });
        }
        return mval.second;
    }
};

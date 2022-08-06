// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        set<int> tnums;
        for (int i=n-1; i>=0; --i) {
            auto itr = tnums.lower_bound(nums[i]);
            if (itr != tnums.begin()) {
                --itr;
                if (i-1>=0 && mvals[i-1]<*itr) return true; 
            }
            tnums.insert(nums[i]);
        }
        return false;
    }
};

// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        int id = n;
        for (int i=n-1; i>=1; --i) {
            if (nums[i] <= mvals[i-1]) continue;
            while (id<n && nums[id]<=mvals[i-1]) ++id;
            if (id<n && nums[id]<nums[i]) return true;
            --id;
            nums[id] = nums[i];
        }
        return false;
    }
};

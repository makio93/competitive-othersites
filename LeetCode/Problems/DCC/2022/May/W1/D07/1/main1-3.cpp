// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        int ri = n;
        for (int i=n-1; i>=1; --i) {
            if (nums[i] <= mvals[i]) continue;
            while (ri<n && nums[ri]<=mvals[i]) ++ri;
            if (ri<n && nums[ri]<nums[i]) return true;
            if (ri>=n || nums[i]<nums[ri]) {
                --ri;
                nums[ri] = nums[i];
            }
        }
        return false;
    }
};

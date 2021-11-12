#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minStartValue(vector<int>& nums) {
        int n = nums.size();
        for (int i=0; i<n-1; ++i) nums[i+1] += nums[i];
        int mval = nums[0];
        for (int i=1; i<n; ++i) mval = min(mval, nums[i]);
        return max(1, -mval+1);
    }
};

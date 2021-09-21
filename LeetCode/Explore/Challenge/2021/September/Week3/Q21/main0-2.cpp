#include <bits/stdc++.h>
using namespace std;

// 自力AC2

class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size(), res = 0, nval = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] == 1) ++nval;
            else if (nval > 0) nval = 0;
            res = max(res, nval);
        }
        return res;
    }
};

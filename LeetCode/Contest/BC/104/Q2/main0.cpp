// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int matrixSum(vector<vector<int>>& nums) {
        int n = nums.size(), m = nums.front().size(), res = 0;
        for (int i=0; i<n; ++i) sort(nums[i].rbegin(), nums[i].rend());
        for (int i=0; i<m; ++i) {
            int mval = -1;
            for (int j=0; j<n; ++j) mval = max(mval, nums[j][i]);
            res += mval;
        }
        return res;
    }
};

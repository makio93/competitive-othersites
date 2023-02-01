// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int differenceOfSum(vector<int>& nums) {
        int n = nums.size(), res = accumulate(nums.begin(), nums.end(), 0);
        for (int i=0; i<n; ++i) while (nums[i] > 0) {
            res -= nums[i] % 10;
            nums[i] /= 10;
        }
        return abs(res);
    }
};

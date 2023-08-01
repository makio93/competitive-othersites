// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long zeroFilledSubarray(vector<int>& nums) {
        int n = nums.size(), zero = 0;
        long long res = 0;
        for (int i=0; i<n; ++i) {
            if (nums[i] != 0) zero = 0;
            else {
                ++zero;
                res += zero;
            }
        }
        return res;
    }
};

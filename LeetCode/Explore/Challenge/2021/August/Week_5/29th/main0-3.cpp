#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int minPatches(vector<int>& nums, int n) {
        int m = nums.size(), res = 0;
        long long val = 0;
        for (int i=0; i<m; ++i) {
            if (val >= (long long)n) break;
            while ((long long)(nums[i])>val+1 && (long long)n>val) {
                ++res;
                val += val + 1;
            }
            val += nums[i];
        }
        while ((long long)n > val) {
            ++res;
            val += val+1;
        }
        return res;
    }
};

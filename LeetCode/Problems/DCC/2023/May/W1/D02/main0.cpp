// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int arraySign(vector<int>& nums) {
        int n = nums.size();
        if (find(nums.begin(), nums.end(), 0) != nums.end()) return 0;
        int res = 1;
        for (int i=0; i<n; ++i) if (nums[i] < 0) res = -res;
        return res;
    }
};

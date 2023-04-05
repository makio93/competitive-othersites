// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size(), res = 0;
        long long sum = 0;
        for (int i=0; i<n; ++i) {
            sum += nums[i];
            res = max(res, (int)((sum+i)/(i+1)));
        }
        return res;
    }
};

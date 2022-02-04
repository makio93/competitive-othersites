#include <bits/stdc++.h>
using namespace std;

// 解説AC,配列を使用

class Solution {
public:
    int findMaxLength(vector<int>& nums) {
        int n = nums.size(), sum = 0, res = 0;
        vector<int> vcnt(n*2+1, (int)(1e9));
        vcnt[n] = -1;
        for (int i=0; i<n; ++i) {
            sum += nums[i] * 2 - 1;
            vcnt[n+sum] = min(vcnt[n+sum], i);
            res = max(res, i-vcnt[n+sum]);
        }
        return res;
    }
};

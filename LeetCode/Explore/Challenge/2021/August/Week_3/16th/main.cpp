#include <bits/stdc++.h>
using namespace std;

// 自力AC

class NumArray {
    vector<int> sum;
public:
    NumArray(vector<int>& nums) {
        int n = nums.size();
        sum = vector<int>(n+1);
        for (int i=0; i<n; ++i) sum[i+1] = sum[i] + nums[i];
    }
    int sumRange(int left, int right) {
        return sum[right+1] - sum[left];
    }
};

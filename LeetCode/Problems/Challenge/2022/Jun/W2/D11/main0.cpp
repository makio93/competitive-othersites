// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        int n = nums.size(), sum = 0, li = 0, res = n+1, val = 0;
        while (li<n && sum+nums[li]<=x) {
            sum += nums[li];
            ++li; ++val;
        }
        int ri = n-1;
        while (li >= 0) {
            while (li<=ri && sum<x) {
                sum += nums[ri];
                --ri; ++val;
            }
            if (sum == x) res = min(res, val);
            --li; --val;
            if (li >= 0) sum -= nums[li];
        }
        if (res == n+1) res = -1;
        return res;
    }
};

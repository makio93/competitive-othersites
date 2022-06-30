// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i=0; i<n/2; ++i) res += nums[n-i-1] - nums[i];
        return res;
    }
};

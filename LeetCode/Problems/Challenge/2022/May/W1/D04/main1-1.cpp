// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxOperations(vector<int>& nums, int k) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0, ri = n-1;
        for (int i=0; i<n; ++i) {
            while (i<ri && nums[i]+nums[ri]>k) --ri;
            if (ri <= i) break;
            if (nums[i]+nums[ri] == k) {
                ++res;
                --ri;
            }
        }
        return res;
    }
};

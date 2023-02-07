// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int n = nums.size(), ncnt = 1;
        sort(nums.begin(), nums.end());
        for (int i=1; i<n; ++i) {
            if (nums[i-1] == nums[i]) ++ncnt;
            else ncnt = 1;
            if (ncnt > n/2) return nums[i];
        }
        return nums.front();
    }
};

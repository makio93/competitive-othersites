// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minMoves2(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int& vi : nums) res += abs(vi - nums[n/2]);
        return res;
    }
};

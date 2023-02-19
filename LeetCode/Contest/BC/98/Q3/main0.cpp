// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minImpossibleOR(vector<int>& nums) {
        int n = nums.size(), res = 1;
        sort(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            if (nums[i] < res) continue;
            if (nums[i] > res) break;
            if (nums[i] == res) res <<= 1;
        }
        return res;
    }
};

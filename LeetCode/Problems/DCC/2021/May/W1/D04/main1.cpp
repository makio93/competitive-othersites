#include <bits/stdc++.h>
using namespace std;

// 解説AC,データ書き換えあり

class Solution {
public:
    bool checkPossibility(vector<int>& nums) {
        int n = nums.size(), mcnt = 0;
        for (int i=0; i+1<n; ++i) {
            if (nums[i+1] < nums[i]) {
                ++mcnt;
                if (i-1>=0 && nums[i-1]>nums[i+1]) nums[i+1] = nums[i];
                else nums[i] = nums[i+1];
            }
            if (mcnt > 1) return false;
        }
        return true;
    }
};

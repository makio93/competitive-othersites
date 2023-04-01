// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int n = nums.size(), res = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        if (res==n || nums[res]!=target) return -1;
        else return res;
    }
};

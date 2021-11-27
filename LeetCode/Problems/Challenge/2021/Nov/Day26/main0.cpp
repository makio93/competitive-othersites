#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int n = nums.size();
        return distance(nums.begin(), lower_bound(nums.begin(), nums.end(), target));
    }
};

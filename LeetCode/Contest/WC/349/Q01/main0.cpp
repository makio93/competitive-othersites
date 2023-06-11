// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findNonMinOrMax(vector<int>& nums) {
        int n = nums.size();
        if (n <= 2) return -1;
        int lval = *min_element(nums.begin(), nums.end()), rval = *max_element(nums.begin(), nums.end());
        for (int i=0; i<n; ++i) {
            if (lval != nums[i] && rval != nums[i]) return nums[i];
        }
        return -1;
    }
};

// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), down = 1, up = 1;
        for (int i=1; i<n; ++i) {
            if (nums[i] > nums[i-1]) up = max(up, down+1);
            else if (nums[i] < nums[i-1]) down = max(down, up+1);
        }
        return max(down, up);
    }
};

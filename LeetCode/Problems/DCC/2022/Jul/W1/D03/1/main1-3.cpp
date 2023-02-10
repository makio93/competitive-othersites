// 学習1回目,解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int wiggleMaxLength(vector<int>& nums) {
        int n = nums.size(), up = 1, down = 1;
        for (int i=1; i<n; ++i) {
            int nup = up, ndown = down;
            if (nums[i] > nums[i-1]) nup = max(up, down+1);
            if (nums[i] < nums[i-1]) ndown = max(down, up+1);
            up = nup, down = ndown;
        }
        return max(up, down);
    }
};

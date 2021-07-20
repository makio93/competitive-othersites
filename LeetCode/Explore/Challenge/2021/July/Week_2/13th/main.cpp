#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findPeakElement(vector<int>& nums) {
        int n = nums.size(), l = -1, r = n, c = (l + r) / 2;
        while (r-l > 2) {
            int lc = (l + c) / 2, rc = (c + r + 1) / 2;
            if (nums[lc] > nums[c]) { r = c; c = (l+r)/2; }
            else if (nums[rc] > nums[c]) { l = c; c = (l+r)/2; }
            else { l = lc; r = rc; c = (l+r)/2; }
        }
        return c;
    }
};

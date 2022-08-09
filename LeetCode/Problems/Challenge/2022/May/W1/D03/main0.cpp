// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), res = 0;
        auto tars = nums;
        sort(tars.begin(), tars.end());
        int li = n, ri = -1;
        for (int i=0; i<n; ++i) if (nums[i] != tars[i]) {
            li = min(li, i);
            ri = max(ri, i);
        }
        if (li == n) return 0;
        else return ri - li + 1;
    }
};

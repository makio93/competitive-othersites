// 解説AC3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), lval = INF, rval = -INF;
        bool avail = false;
        for (int i=1; i<n; ++i) {
            if (nums[i] < nums[i-1]) avail = true;
            if (avail) lval = min(lval, nums[i]);
        }
        avail = false;
        for (int i=n-2; i>=0; --i) {
            if (nums[i] > nums[i+1]) avail = true;
            if (avail) rval = max(rval, nums[i]);
        }
        if (lval == INF) return 0;
        int li = 0, ri = n-1;
        while (li<n && nums[li]<=lval) ++li;
        while (ri>=0 && nums[ri]>=rval) --ri;
        return ri - li + 1;
    }
};

// 学習1回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), lv = INF, rv = -INF;
        for (int i=0; i<n-1; ++i) if (nums[i+1] < nums[i]) {
            lv = min(lv, nums[i+1]);
            rv = max(rv, nums[i]);
        }
        if (lv == INF) return 0;
        int li = 0, ri = n-1;
        while (li<n && nums[li]<=lv) ++li;
        while (ri>=0 && nums[ri]>=rv) --ri;
        return max(0, ri-li+1);
    }
};

#include <bits/stdc++.h>
using namespace std;

// 解説実装2,AC,vector使用

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        int sum = 0;
        for (int i=0; i<n; ++i) sum += nums[i];
        vector<vector<int>> lvals(m+1), rvals(m+1);
        for (int i=0; i<(1<<m); ++i) {
            int lval = 0, rval = 0, bcnt = 0;
            for (int j=0; j<m; ++j) if ((i>>j)&1) {
                lval += nums[j];
                rval += nums[m+j];
                ++bcnt;
            }
            lvals[bcnt].push_back(lval);
            rvals[bcnt].push_back(rval);
        }
        for (int i=0; i<=m; ++i) {
            sort(lvals[i].begin(), lvals[i].end());
            sort(rvals[i].begin(), rvals[i].end());
        }
        int res = abs(sum-rvals[m][0]*2);
        for (int i=1; i<=m; ++i) {
            for (int& lv : lvals[i]) {
                int tv = (sum-lv*2) / 2;
                auto itr = lower_bound(rvals[m-i].begin(), rvals[m-i].end(), tv);
                if (itr != rvals[m-i].end()) res = min(res, abs(sum-(lv+*itr)*2));
                if (itr != rvals[m-i].begin()) {
                    --itr;
                    res = min(res, abs(sum-(lv+*itr)*2));
                }
            }
        }
        return res;
    }
};

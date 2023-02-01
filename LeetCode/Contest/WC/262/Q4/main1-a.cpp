#include <bits/stdc++.h>
using namespace std;

// 解説実装1,TLE,set使用

class Solution {
public:
    int minimumDifference(vector<int>& nums) {
        int n = nums.size(), m = n / 2;
        int sum = 0;
        for (int i=0; i<n; ++i) sum += nums[i];
        vector<set<int>> lvals(m+1), rvals(m+1);
        for (int i=0; i<(1<<m); ++i) {
            int lval = 0, rval = 0, bcnt = 0;
            for (int j=0; j<m; ++j) if ((i>>j)&1) {
                lval += nums[j];
                rval += nums[m+j];
                ++bcnt;
            }
            lvals[bcnt].insert(lval);
            rvals[bcnt].insert(rval);
        }
        int res = abs(sum-*rvals[m].begin()*2);
        for (int i=1; i<=m; ++i) {
            for (int lv : lvals[i]) {
                int tv = (sum-lv*2) / 2;
                auto itr = rvals[m-i].lower_bound(tv);
                if (itr != rvals[m-i].end()) res = min(res, abs(sum-(lv+*itr)*2));
                if (itr != rvals[m-i].begin()) {
                    itr = prev(itr);
                    res = min(res, abs(sum-(lv+*itr)*2));
                }
            }
        }
        return res;
    }
};

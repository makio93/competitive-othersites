// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int, int>> vals(n);
        for (int i=0; i<n; ++i) vals[i] = { nums[i], i };
        auto calc = [&](auto calc, int li, int ri) -> void {
            if (ri-li <= 1) return;
            int mi = li + (ri - li) / 2;
            calc(calc, li, mi);
            calc(calc, mi, ri);
            int tid = mi;
            for (int i=li; i<mi; ++i) {
                while (tid<ri && vals[tid].first<vals[i].first) ++tid;
                res[vals[i].second] += tid - mi;
            }
            inplace_merge(vals.begin()+li, vals.begin()+mi, vals.begin()+ri);
        };
        calc(calc, 0, n);
        return res;
    }
};

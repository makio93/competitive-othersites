// 解説AC1-2

#include <bits/stdc++.h>
using namespace std;

typedef vector<pair<int, int>>::iterator vitr;
class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n);
        vector<pair<int, int>> vals(n);
        for (int i=0; i<n; ++i) vals[i] = { nums[i], i };
        auto calc = [&](auto calc, vitr li, vitr ri) -> void {
            if (ri-li <= 1) return;
            auto mi = li + (ri - li) / 2;
            calc(calc, li, mi);
            calc(calc, mi, ri);
            auto tid = mi;
            for (auto id=li; id<mi; ++id) {
                while (tid<ri && tid->first<id->first) ++tid;
                res[id->second] += tid - mi;
            }
            inplace_merge(li, mi, ri);
        };
        calc(calc, vals.begin(), vals.end());
        return res;
    }
};

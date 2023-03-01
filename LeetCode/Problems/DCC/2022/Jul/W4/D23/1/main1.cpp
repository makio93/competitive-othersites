// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vlst(n);
        for (int i=0; i<n; ++i) vlst[i] = { nums[i], i };
        vector<int> res(n);
        auto calc = [&](auto calc, int li, int ri) -> void {
            if (ri-li <= 1) return;
            int mi = li + (ri-li) / 2;
            calc(calc, li, mi);
            calc(calc, mi, ri);
            for (int i=li,j=mi; i<mi; ++i) {
                while (j<ri && vlst[j].first<vlst[i].first) ++j;
                res[vlst[i].second] += j - mi;
            }
            inplace_merge(vlst.begin()+li, vlst.begin()+mi, vlst.begin()+ri);
        };
        calc(calc, 0, n);
        return res;
    }
};

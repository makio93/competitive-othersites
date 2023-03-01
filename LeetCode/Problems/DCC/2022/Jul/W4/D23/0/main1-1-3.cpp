// 解説AC1-3

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
            vector<pair<int, int>> tmp;
            tmp.reserve(ri-li);
            auto tid = mi;
            for (auto id=li; id<mi; ++id) {
                while (tid<ri && tid->first<id->first) {
                    tmp.push_back(*tid);
                    ++tid;
                }
                tmp.push_back(*id);
                res[id->second] += tid - mi;
            }
            while (tid < ri) {
                tmp.push_back(*tid);
                ++tid;
            }
            move(tmp.begin(), tmp.end(), li);
        };
        calc(calc, vals.begin(), vals.end());
        return res;
    }
};

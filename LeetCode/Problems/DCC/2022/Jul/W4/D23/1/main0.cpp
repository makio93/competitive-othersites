// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int, int>> vlst(n);
        for (int i=0; i<n; ++i) vlst[i] = { nums[i], i };
        sort(vlst.begin(), vlst.end());
        vector<int> data(n+1), res(n);
        auto add = [&](int id) -> void {
            for (++id; id<=n; id+=id&-id) data[id]++;
        };
        auto sum = [&](int id) -> int {
            int sval = 0;
            for (++id; id>=1; id-=id&-id) sval += data[id];
            return sval;
        };
        auto qry = [&](int li, int ri) -> int {
            return sum(ri-1) - sum(li-1);
        };
        for (int i=0; i<n; ++i) {
            add(vlst[i].second);
            res[vlst[i].second] = qry(vlst[i].second+1, n);
        }
        return res;
    }
};

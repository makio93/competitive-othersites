// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        if (n <= 1) return 0;
        function<void(unordered_map<int, int>&, int, int)> f = [&](unordered_map<int, int>& lst, int li, int ri) {
            set<pair<int, int>> tst;
            tst.emplace(0, 0);
            for (int i=li; i<ri; ++i) {
                auto nst = tst;
                for (const auto [lv, rv] : tst) {
                    nst.emplace(lv+rods[i], rv);
                    nst.emplace(lv, rv+rods[i]);
                }
                swap(nst, tst);
            }
            for (const auto [lv, rv] : tst) {
                int dif = rv - lv;
                lst[dif] = max(lst[dif], lv);
            }
        };
        unordered_map<int, int> llst, rlst;
        f(llst, 0, n/2);
        f(rlst, n/2, n);
        int res = 0;
        for (const auto [di, lv] : llst) if (rlst.find(-di) != rlst.end()) res = max(res, lv+rlst[-di]);
        return res;
    }
};

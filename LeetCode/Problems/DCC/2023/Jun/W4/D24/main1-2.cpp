// 解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size();
        unordered_map<int, int> dp;
        dp[0] = 0;
        for (int i=0; i<n; ++i) {
            auto ndp = dp;
            for (const auto [dif, val] : dp) {
                int tdif1 = dif + rods[i], tdif2 = abs(dif - rods[i]);
                int tval1 = val + rods[i], tval2 = max(val, max(val, val-dif+rods[i]));
                ndp[tdif1] = max(ndp[tdif1], tval1);
                ndp[tdif2] = max(ndp[tdif2], tval2);
            }
            swap(ndp, dp);
        }
        return dp[0];
    }
};

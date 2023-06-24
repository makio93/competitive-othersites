// 自力TLE2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), asum = accumulate(rods.begin(), rods.end(), 0), res = 0;
        sort(rods.begin(), rods.end());
        for (int i=1; i<1<<n; ++i) {
            int lsum = 0;
            for (int j=0; j<n; ++j) if (i&(1<<j)) lsum += rods[j];
            if (lsum > asum-lsum || res >= lsum) continue;
            int lsb = i & -i;
            bitset<2501> dp;
            dp[0] = true;
            for (int j=0; j<n; ++j) {
                if ((1<<j) <= lsb || (i&(1<<j))) continue;
                dp |= dp << rods[j];
                if (dp[lsum]) break;
            }
            if (dp[lsum]) res = max(res, lsum);
        }
        return res;
    }
};

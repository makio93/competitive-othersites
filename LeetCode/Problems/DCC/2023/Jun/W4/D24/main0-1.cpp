// 自力TLE1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int tallestBillboard(vector<int>& rods) {
        int n = rods.size(), asum = accumulate(rods.begin(), rods.end(), 0), res = 0;
        for (int i=1; i<1<<n; ++i) {
            int lsum = 0;
            for (int j=0; j<n; ++j) if (i&(1<<j)) lsum += rods[j];
            if (lsum > asum-lsum) continue;
            int lsb2 = (i & -i) << 1;
            for (int j=lsb2; j<1<<n; j+=lsb2) if ((i&j) == 0) {
                int rsum = 0;
                for (int j2=0; j2<n; ++j2) if (j&(1<<j2)) rsum += rods[j2];
                if (lsum == rsum) {
                    res = max(res, lsum);
                    break;
                }
            }
        }
        return res;
    }
};

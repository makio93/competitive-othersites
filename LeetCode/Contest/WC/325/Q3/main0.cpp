// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maximumTastiness(vector<int>& price, int k) {
        int n = price.size();
        sort(price.begin(), price.end());
        int li = 0, ri = price.back() + 1;
        while (ri-li > 1) {
            int ci = li + (ri-li) / 2, pval = price[0], kcnt = 1, kval = 0;
            for (int i=1; i<n; ++i) if (price[i]-pval >= ci) {
                ++kcnt;
                pval = price[i];
            }
            kval = kcnt;
            kcnt = 1, pval = price[n-1];
            for (int i=n-2; i>=0; --i) if (pval-price[i] >= ci) {
                ++kcnt;
                pval = price[i];
            }
            kval = max(kval, kcnt);
            if (kval >= k) li = ci;
            else ri = ci;
        }
        return li;
    }
};

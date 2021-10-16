#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        vector<int> lmval(n);
        int res = 0;
        set<int> lvals({prices[0]}), rvals({prices[n-1]});
        for (int i=1; i<n; ++i) {
            lmval[i] = max(0, prices[i]-*lvals.begin());
            lvals.insert(prices[i]);
        }
        for (int i=1; i<n; ++i) lmval[i] = max(lmval[i], lmval[i-1]);
        for (int i=n-2; i>=1; --i) {
            int rval = max(0, *rvals.rbegin()-prices[i]);
            res = max(res, lmval[i-1]+rval);
            rvals.insert(prices[i]);
        }
        res = max(res, *rvals.rbegin()-prices[0]);
        return res;
    }
};

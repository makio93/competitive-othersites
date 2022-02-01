#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n = prices.size(), mval = (int)(1e9), res = 0;
        for (int i=0; i<n; ++i) {
            mval = min(mval, prices[i]);
            res = max(res, prices[i]-mval);
        }
        return res;
    }
};

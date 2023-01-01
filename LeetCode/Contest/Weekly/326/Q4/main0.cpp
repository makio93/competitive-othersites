// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    vector<int> closestPrimes(int left, int right) {
        vector<bool> sie(right+1);
        int pval = -1;
        pair<int, int> mval = { INF, INF };
        for (int i=2; i<=right; ++i) if (!sie[i]) {
            if (pval!=-1 && pval>=left) mval = min(mval, { i-pval, pval });
            pval = i;
            for (int j=i*2; j<=right; j+=i) sie[j] = true;
        }
        vector<int> res = { -1, -1 };
        if (mval.first != INF) {
            res[0] = mval.second;
            res[1] = mval.second + mval.first;
        }
        return res;
    }
};

// 自力WA1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size(), res = 0;
        sort(cuts.begin(), cuts.end());
        vector<int> vals;
        vals.push_back(cuts[0]);
        for (int i=0; i<m-1; ++i) vals.push_back(cuts[i+1]-cuts[i]);
        vals.push_back(n-cuts[m-1]);
        while ((int)(vals.size()) > 1) {
            vector<int> tvals;
            pair<int, int> mval = { INF, -1 };
            int k = vals.size();
            for (int i=0; i+1<k; ++i) mval = min(mval, { vals[i]+vals[i+1], i });
            res += mval.first;
            for (int i=0; i<k; ++i) {
                if (i==mval.second || i==mval.second+1) {
                    if (i == mval.second) tvals.push_back(mval.first);
                }
                else tvals.push_back(vals[i]);
            }
            swap(tvals, vals);
        }
        return res;
    }
};

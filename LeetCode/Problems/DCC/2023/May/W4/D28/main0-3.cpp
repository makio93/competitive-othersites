// 自力WA3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minCost(int n, vector<int>& cuts) {
        int m = cuts.size(), res = 0;
        sort(cuts.begin(), cuts.end());
        vector<pair<int, int>> vals;
        vals.emplace_back(cuts[0], 0);
        for (int i=0; i<m-1; ++i) vals.emplace_back(cuts[i+1]-cuts[i], 0);
        vals.emplace_back(n-cuts[m-1], 0);
        while ((int)(vals.size()) > 1) {
            vector<pair<int, int>> tvals;
            pair<int, int> mval = { INF, -1 };
            int k = vals.size();
            for (int i=0; i+1<k; ++i) mval = min(mval, { vals[i].second+vals[i+1].second+vals[i].first+vals[i+1].first, i });
            res += vals[mval.second].first + vals[mval.second+1].first;
            for (int i=0; i<k; ++i) {
                if (i==mval.second || i==mval.second+1) {
                    if (i == mval.second) tvals.emplace_back(vals[mval.second].first+vals[mval.second+1].first, vals[mval.second].first+vals[mval.second+1].first+vals[mval.second].second+vals[mval.second+1].second);
                }
                else tvals.push_back(vals[i]);
            }
            swap(tvals, vals);
        }
        return res;
    }
};

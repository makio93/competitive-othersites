#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> maximumBeauty(vector<vector<int>>& items, vector<int>& queries) {
        int n = items.size(), m = queries.size();
        map<int, int> mvals;
        mvals[0] = 0;
        for (int i=0; i<n; ++i) mvals[items[i][0]] = max(mvals[items[i][0]], items[i][1]);
        int mval = 0;
        for (auto& pi : mvals) {
            mval = max(mval, pi.second);
            pi.second = mval;
        }
        vector<int> res(m);
        for (int i=0; i<m; ++i) {
            res[i] = prev(mvals.upper_bound(queries[i]))->second;
        }
        return res;
    }
};

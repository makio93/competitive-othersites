#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int leastBricks(vector<vector<int>>& wall) {
        int n = wall.size(), mval = 0;
        vector<vector<long long>> swall(n);
        vector<vector<int>> twall(n);
        vector<long long> vlst;
        vlst.push_back(0);
        for (int i=0; i<n; ++i) {
            long long tval = 0;
            swall[i].push_back(tval);
            for (int val : wall[i]) {
                tval += val;
                vlst.push_back(tval);
                swall[i].push_back(tval);
            }
        }
        sort(vlst.begin(), vlst.end());
        vlst.erase(unique(vlst.begin(), vlst.end()), vlst.end());
        for (int i=0; i<n; ++i) for (long long sval : swall[i]) {
            twall[i].push_back(distance(vlst.begin(), lower_bound(vlst.begin(), vlst.end(), sval)));
        }
        int ri = vlst.size() - 1;
        vector<int> rcnt(ri+1);
        for (int i=0; i<n; ++i) for (int tval : twall[i]) rcnt[tval]++;
        for (int i=1; i<ri; ++i) mval = max(mval, rcnt[i]);
        return n - mval;
    }
};

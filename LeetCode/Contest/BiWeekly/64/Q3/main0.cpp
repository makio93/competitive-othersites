#include <bits/stdc++.h>
using namespace std;

// 本番AC

class Solution {
public:
    vector<int> platesBetweenCandles(string s, vector<vector<int>>& queries) {
        int n = s.length(), m = queries.size();
        vector<int> psum(n+1), clst;
        for (int i=0; i<n; ++i) {
            psum[i+1] = psum[i];
            if (s[i] == '*') psum[i+1]++;
            else clst.push_back(i+1);
        }
        int clen = clst.size();
        vector<int> res(m);
        for (int i=0; i<m; ++i) {
            int lid = lower_bound(clst.begin(), clst.end(), queries[i][0]+1) - clst.begin();
            int rid = lower_bound(clst.begin(), clst.end(), queries[i][1]+2) - clst.begin() - 1;
            if ((lid<clen&&rid>=0) && rid>=lid) {
                int lp = clst[lid], rp = clst[rid];
                res[i] = psum[rp] - psum[lp-1];
            }
        }
        return res;
    }
};

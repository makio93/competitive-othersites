#include <bits/stdc++.h>
using namespace std;

// 本番AC

const int INF = (int)(1e9);
class Solution {
public:
    int minimumTime(string s) {
        int n = s.length();
        vector<int> bids;
        bids.push_back(0);
        for (int i=0; i<n; ++i) if (s[i] == '1') bids.push_back(i+1);
        bids.push_back(n+1);
        int m = bids.size();
        if (m-2 == 0) return 0;
        else if (m-2 == n) return n;
        else if (m-2>8 && m-2>n/4*3) return min(n-bids[1]+1, bids[m-2]);
        else {
            vector<vector<int>> ldp(m, vector<int>(2, INF)), rdp(m, vector<int>(2, INF));
            ldp[0][0] = ldp[0][1] = 0;
            for (int i=1; i<m-1; ++i) {
                int llen = bids[i] - bids[i-1];
                ldp[i][1] = min(ldp[i][1], min(ldp[i-1][1]+2, ldp[i-1][0]+2));
                ldp[i][0] = min(ldp[i][0], ldp[i-1][0]+llen);
            }
            rdp[m-1][0] = rdp[m-1][1] = 0;
            for (int i=1; i<m-1; ++i) {
                int rlen = bids[m-i] - bids[m-i-1];
                rdp[m-i-1][1] = min(rdp[m-i-1][1], min(rdp[m-i][1]+2, rdp[m-i][0]+2));
                rdp[m-i-1][0] = min(rdp[m-i-1][0], rdp[m-i][0]+rlen);
            }
            int res = INF;
            for (int i=0; i<m-1; ++i) res = min(res, min(ldp[i][0], ldp[i][1])+min(rdp[i+1][0], rdp[i+1][1]));
            return res;
        }
    }
};

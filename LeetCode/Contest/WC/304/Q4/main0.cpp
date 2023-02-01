// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int longestCycle(vector<int>& edges) {
        int n = edges.size();
        vector<int> cnts(n, -1);
        int cid = 0, res = -1;
        vector<int> dist(n, INF);
        for (int i=0; i<n; ++i) if (cnts[i] == -1) {
            int vi = i, di = 0;
            dist[vi] = di;
            cnts[vi] = cid;
            while (edges[vi] != -1) {
                vi = edges[vi];
                ++di;
                if (cnts[vi] != -1) {
                    if (cnts[vi] == cid) {
                        res = max(res, di-dist[vi]);
                    }
                    break;
                }
                dist[vi] = di;
                cnts[vi] = cid;
            }
            ++cid;
        }
        return res;
    }
};

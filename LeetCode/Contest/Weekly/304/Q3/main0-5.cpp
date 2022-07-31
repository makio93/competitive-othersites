// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        int n = edges.size();
        vector<int> dist1(n, INF), dist2(n, INF);
        queue<int> que;
        que.push(node1);
        dist1[node1] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist1[vi], ndi = di + 1, ti = edges[vi];
            if (ti != -1) {
                if (dist1[ti] <= ndi) continue;
                dist1[ti] = ndi;
                que.push(ti);
            }
        }
        que.push(node2);
        dist2[node2] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist2[vi], ndi = di + 1, ti = edges[vi];
            if (ti != -1) {
                if (dist2[ti] <= ndi) continue;
                dist2[ti] = ndi;
                que.push(ti);
            }
        }
        pair<int, int> mval = { INF, -1 };
        for (int i=0; i<n; ++i) if (dist1[i]!=INF && dist2[i]!=INF) mval = min(mval, { max(dist1[i], dist2[i]), i });
        return mval.second;
    }
};

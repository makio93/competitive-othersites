// 本番WA3

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
const int BIG = (int)(5e5);
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
            int di = dist1[vi], ti = edges[vi];
            if (ti==-1 || (dist1[ti]!=INF&&dist1[ti]>=BIG)) continue;
            int ndi = di + 1;
            if (dist1[ti]<BIG && ndi<BIG) ndi += BIG;
            dist1[ti] = ndi;
            que.push(ti);
        }
        que.push(node2);
        dist2[node2] = 0;
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist2[vi], ti = edges[vi];
            if (ti==-1 || (dist2[ti]!=INF&&dist2[ti]>=BIG)) continue;
            int ndi = di + 1;
            if (dist2[ti]<BIG && ndi<BIG) ndi += BIG;
            dist2[ti] = ndi;
            que.push(ti);
        }
        pair<int, int> mval = { INF, -1 };
        for (int i=0; i<n; ++i) if (dist1[i]!=INF && dist2[i]!=INF) mval = min(mval, { dist1[i]+dist2[i], i });
        return mval.second;
    }
};

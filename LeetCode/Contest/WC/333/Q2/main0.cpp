// 本番AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int minOperations(int n) {
        int m = n * 4;
        vector<int> dist(m+1, INF);
        queue<int> que;
        dist[n] = 0;
        que.push(n);
        while (!que.empty()) {
            int vi = que.front(); que.pop();
            int di = dist[vi], ndi = di + 1;
            for (int i=1; i<=m; i<<=1) {
                int ti = vi + i;
                if (ti>=0 && ti<=m && dist[ti]>ndi) {
                    dist[ti] = ndi;
                    que.push(ti);
                }
                ti = vi - i;
                if (ti>=0 && ti<=m && dist[ti]>ndi) {
                    dist[ti] = ndi;
                    que.push(ti);
                }
            }
        }
        return dist[0];
    }
};

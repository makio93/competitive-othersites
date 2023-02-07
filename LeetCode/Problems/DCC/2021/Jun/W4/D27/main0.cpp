#include <bits/stdc++.h>
using namespace std;

// 自力AC

const int INF = (int)(1e9);
class Solution {
public:
    int candy(vector<int>& ratings) {
        int n = ratings.size();
        vector<vector<int>> g(n);
        vector<int> din(n);
        for (int i=0; i<n; ++i) {
            if (i-1>=0 && ratings[i-1]>ratings[i]) {
                g[i].push_back(i-1);
                din[i-1]++;
            }
            if (i+1<n && ratings[i+1]>ratings[i]) {
                g[i].push_back(i+1);
                din[i+1]++;
            }
        }
        vector<int> dist(n, INF);
        queue<int> que;
        for (int i=0; i<n; ++i) if (din[i] == 0) {
            dist[i] = 1;
            que.push(i);
        }
        while (!que.empty()) {
            int v = que.front(); que.pop();
            int d = dist[v], nd = d + 1;
            for (int t : g[v]) {
                if (dist[t]!=INF && dist[t]>=nd) continue;
                dist[t] = nd;
                que.push(t);
            }
        }
        int res = 0;
        for (int i=0; i<n; ++i) res += dist[i];
        return res;
    }
};

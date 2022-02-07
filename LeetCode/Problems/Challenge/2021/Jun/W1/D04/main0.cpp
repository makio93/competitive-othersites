#include <bits/stdc++.h>
using namespace std;

// 自力AC1

const int INF = (int)(1e9);
class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        int n = deadends.size();
        vector<int> dist(10000, INF);
        for (int i=0; i<n; ++i) dist[stoi(deadends[i])] = -1;
        if (dist[0] == -1) return -1;
        queue<int> que;
        dist[0] = 0;
        que.push(0);
        while (!que.empty()) {
            int val = que.front(); que.pop();
            int d = dist[val];
            vector<int> dvals(4);
            int tval = val;
            for (int i=0; i<4; ++i) {
                dvals[i] = tval % 10;
                tval /= 10;
            }
            for (int i=0; i<4; ++i) {
                vector<int> dd = { 1, -1 };
                for (int j=0; j<2; ++j) {
                    auto nvals = dvals;
                    nvals[i] = (nvals[i] + dd[j] + 10) % 10;
                    int nval = 0, ten = 1;
                    for (int j2=0; j2<4; ++j2) {
                        nval += nvals[j2] * ten;
                        ten *= 10;
                    }
                    if (dist[nval] == -1) continue;
                    if (dist[nval] <= d+1) continue;
                    dist[nval] = d+1;
                    que.push(nval);
                }
            }
        }
        if (dist[stoi(target)] != INF) return dist[stoi(target)];
        else return -1;
    }
};

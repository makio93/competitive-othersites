#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int minCost(vector<int>& startPos, vector<int>& homePos, vector<int>& rowCosts, vector<int>& colCosts) {
        int m = rowCosts.size(), n = colCosts.size();
        int dr = homePos[0] - startPos[0], dc = homePos[1] - startPos[1];
        if (dr != 0) dr /= abs(dr);
        if (dc != 0) dc /= abs(dc);
        if (dr==0 && dc==0) return 0;
        vector<vector<ll>> dist(m, vector<ll>(n, (ll)(1e18)));
        priority_queue<tuple<ll, int, int>, vector<tuple<ll, int, int>>, greater<tuple<ll, int, int>>> que;
        dist[startPos[0]][startPos[1]] = 0;
        que.emplace(0, startPos[0], startPos[1]);
        while (!que.empty()) {
            auto [d, y, x] = que.top(); que.pop();
            if (dist[y][x] != d) continue;
            if (dr != 0) {
                int ny = y + dr, nx = x;
                if (ny>=0 && ny<m && nx>=0 && nx<n) {
                    ll nd = d + rowCosts[ny];
                    if (dist[ny][nx] > nd) {
                        dist[ny][nx] = nd;
                        if (ny!=homePos[0] || nx!=homePos[1]) que.emplace(nd, ny, nx);
                    }
                }
            }
            if (dc != 0) {
                int ny = y, nx = x + dc;
                if (ny>=0 && ny<m && nx>=0 && nx<n) {
                    ll nd = d + colCosts[nx];
                    if (dist[ny][nx] > nd) {
                        dist[ny][nx] = nd;
                        if (ny!=homePos[0] || nx!=homePos[1]) que.emplace(nd, ny, nx);
                    }
                }
            }
        }
        return (int)dist[homePos[0]][homePos[1]];
    }
};

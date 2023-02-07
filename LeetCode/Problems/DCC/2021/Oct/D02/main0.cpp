#include <bits/stdc++.h>
using namespace std;

// 自力AC

class Solution {
public:
    int calculateMinimumHP(vector<vector<int>>& dungeon) {
        int n = dungeon.size(), m = dungeon.front().size();
        vector<vector<map<int, int>>> dist(n, vector<map<int, int>>(m));
        priority_queue<tuple<int, int, int, int>> que;
        que.emplace(dungeon[0][0], dungeon[0][0], 0, 0);
        dist[0][0][dungeon[0][0]] = dungeon[0][0];
        while (!que.empty()) {
            auto [mv, vdi, y, x] = que.top(); que.pop();
            if (dist[y][x].find(mv)==dist[y][x].end() || dist[y][x][mv]!=vdi) continue;
            int di = dist[y][x][mv];
            vector<int> dy = { 0, 1 }, dx = { 1, 0 };
            for (int i=0; i<2; ++i) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny>=n || nx>=m) continue;
                int ndi = di + dungeon[ny][nx], nmv = min(mv, ndi);
                if (dist[ny][nx].find(nmv)!=dist[ny][nx].end() && dist[ny][nx][nmv]>=ndi) continue;
                dist[ny][nx][nmv] = ndi;
                auto itr = dist[ny][nx].find(nmv);
                if (next(itr)!=dist[ny][nx].end() && next(itr)->second>=ndi) {
                    dist[ny][nx].erase(itr);
                    continue;
                }
                if (itr!=dist[ny][nx].begin() && prev(itr)->second<=ndi) dist[ny][nx].erase(prev(itr));
                que.emplace(nmv, ndi, ny, nx);
            }
        }
        int sub = (int)(-1e9);
        for (auto pi : dist[n-1][m-1]) sub = max(sub, pi.first);
        int res = max(1, 1-sub);
        return res;
    }
};

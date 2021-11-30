// バチャ本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

class SlowTerrain {
public:
    int fastestPath(vector<string> terrain) {
        int n = terrain.size(), m = terrain.front().length();
        vector<vector<int>> dist(n, vector<int>(m, INF));
        priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> que;
        rep(i, n) rep(j, m) if (terrain[i][j] == 'S') {
            dist[i][j] = 0;
            que.emplace(0, i, j);
        }
        while (!que.empty()) {
            auto tup = que.top(); que.pop();
            int d = get<0>(tup), y = get<1>(tup), x = get<2>(tup);
            if (dist[y][x] != d) continue;
            vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            rep(i, 4) {
                int ny = y + dy[i], nx = x + dx[i];
                if (ny<0 || ny>=n || nx<0 || nx>=m) continue;
                int dd = (terrain[ny][nx] != 'D') ? (terrain[ny][nx] - '0') : 0, nd = d + dd;
                if (dist[ny][nx] <= nd) continue;
                dist[ny][nx] = nd;
                que.emplace(nd, ny, nx);
            }
        }
        int res = -1;
        rep(i, n) rep(j, m) if (terrain[i][j] == 'D') res = dist[i][j];
        return res;
    }
};

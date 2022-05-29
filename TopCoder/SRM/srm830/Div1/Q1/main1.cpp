// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
class Jetpack {
public:
    int travel(vector<string> maze, int T) {
        int n = maze.size(), m = maze.front().length();
        int sy = -1, sx = -1, ty = -1, tx = -1;
        rep(i, n) rep(j, m) {
            if (maze[i][j] == 'A') { sy = i; sx = j; }
            if (maze[i][j] == 'B') { ty = i; tx = j; }
        }
        vector<vector<int>> dista(n, vector<int>(m, INF)), distb(n, vector<int>(m, INF));
        auto search = [&](vector<vector<int>>& dist, int syi, int sxi, int tv) -> void {
            priority_queue<tuple<int, int, int>, vector<tuple<int, int, int>>, greater<tuple<int, int, int>>> pq;
            dist[syi][sxi] = 0;
            pq.emplace(0, syi, sxi);
            while (!pq.empty()) {
                auto pi = pq.top(); pq.pop();
                int di = get<0>(pi), y = get<1>(pi), x = get<2>(pi);
                if (dist[y][x] != di) continue;
                rep(i2, 4) {
                    int ny = y + dy[i2], nx = x + dx[i2];
                    if (ny<0 || ny>=n || nx<0 || nx>=m || maze[ny][nx]=='#') continue;
                    int ndi = di + 1 + (maze[ny][nx]=='_' ? tv : 0);
                    if (dist[ny][nx] <= ndi) continue;
                    dist[ny][nx] = ndi;
                    pq.emplace(ndi, ny, nx);
                }
            }
        };
        search(dista, sy, sx, INF);
        search(distb, ty, tx, T);
        int res = dista[ty][tx];
        rep(i, n) rep(j, m) if (maze[i][j] == 'C') {
            if (dista[i][j]!=INF && distb[i][j]!=INF) res = min(res, dista[i][j]+distb[i][j]);
        }
        if (res == INF) return -1;
        else return res;
    }
};
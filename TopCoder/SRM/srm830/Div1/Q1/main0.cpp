// 本番,システス落ち

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class Jetpack {
    const int INF = (int)(2e9);
    const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
public:
    int travel(vector<string> maze, int T) {
        int n = maze.size(), m = maze.front().length();
        int hcnt = 0;
        rep(i, n) rep(j, m) if (maze[i][j] == '_') ++hcnt;
        int sy = -1, sx = -1, ty = -1, tx = -1;
        rep(i, n) rep(j, m) {
            if (maze[i][j] == 'A') { sy = i; sx = j; }
            if (maze[i][j] == 'B') { ty = i; tx = j; }
        }
        vector<vector<map<int, int>>> dist(n, vector<map<int, int>>(m));
        priority_queue<tuple<int, int, int, int>, vector<tuple<int, int, int, int>>, greater<tuple<int, int, int, int>>> pq;
        dist[sy][sx][0] = 0;
        pq.emplace(0, sy, sx, 0);
        int tar = INF;
        while (!pq.empty()) {
            auto pi = pq.top(); pq.pop();
            int di = get<0>(pi), y = get<1>(pi), x = get<2>(pi), hi = get<3>(pi);
            if (dist[y][x].find(hi)==dist[y][x].end() || dist[y][x][hi]!=di) continue;
            rep(i, 4) {
                int ny = y + dy[i], nx = x + dx[i], ndi = di + 1;
                if (ny<0 || ny>=n || nx<0 || nx>=m || maze[ny][nx]=='#') continue;
                if (maze[ny][nx]=='_' && hi==0) continue;
                int nhi = hi;
                if (maze[ny][nx] == '_') --nhi;
                if (dist[ny][nx].find(nhi)!=dist[ny][nx].end() && dist[ny][nx][nhi]<=ndi) continue;
                if (ndi >= tar) continue;
                dist[ny][nx][nhi] = ndi;
                if (ny==ty && nx==tx && nhi==0) tar = min(tar, ndi);
                pq.emplace(ndi, ny, nx, nhi);
            }
            if (hi+1<=hcnt && maze[y][x]=='C') {
                int nhi = hi + 1, ndi = di + T;
                if (ndi >= tar) continue;
                if (dist[y][x].find(nhi)==dist[y][x].end() || dist[y][x][nhi]>ndi) {
                    dist[y][x][nhi] = ndi;
                    if (y==ty && x==tx && nhi==0) tar = min(tar, ndi);
                    pq.emplace(ndi, y, x, nhi);
                }
            }
        }
        if (dist[ty][tx].find(0) == dist[ty][tx].end()) return -1;
        else return dist[ty][tx][0];
    }
};
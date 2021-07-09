#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説AC

const int INF = (int)(1e9);
const vector<int> dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };

int query(int a, int b, int& qcnt) {
    if (qcnt >= 3000) return -1;
    ++a; ++b; ++qcnt;
    cout << a << " " << b << endl;
    string s;
    cin >> s;
    if (s == (string)"Black") return 1;
    else if (s == (string)"White") return 0;
    else if (s == (string)"-1") return -1;
    else return -1;
}

int main() {
    int n, m;
    cin >> n >> m;
    cin.ignore();
    vector<vector<int>> b(n, vector<int>(n, -1));
    b[0][0] = b[n-1][n-1] = 1;
    queue<pair<int, int>> que;
    vector<vector<int>> dist(n, vector<int>(n, INF));
    int mcnt = 1, qcnt = 0;
    bool ok = false;
    que.emplace(0, 0);
    dist[0][0] = 0;
    while (!que.empty()) {
        auto p = que.front(); que.pop();
        int y = p.first, x = p.second, d = dist[y][x];
        rep(i1, 4) {
            int ny = y + dy[i1], nx = x + dx[i1];
            if (ny<0 || ny>=n || nx<0 || nx>=n) continue;
            if (ny==n-1 && nx==n-1) {
                ok = true;
                break;
            }
            if (dist[ny][nx] <= d+1) continue;
            if (b[ny][nx] == -1) {
                if (mcnt >= m) {
                    if (ok) cout << "Yes" << endl;
                    else cout << "No" << endl;
                    return 0;
                }
                int qres = query(ny, nx, qcnt);
                if (qres == -1) {
                    if (ok) cout << "Yes" << endl;
                    else cout << "No" << endl;
                    return 0;
                }
                b[ny][nx] = qres;
            }
            if (b[ny][nx] == 0) continue;
            if (b[ny][nx] == 1) {
                que.emplace(ny, nx);
                dist[ny][nx] = d + 1;
                ++mcnt;
            }
        }
        if (ok || mcnt>=m || qcnt>=3000) {
            if (ok) cout << "Yes" << endl;
            else cout << "No" << endl;
            return 0;
        }
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

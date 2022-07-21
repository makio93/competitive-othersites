// 終了後,自力,WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;
#define v(t) vector<t>
#define p(t) pair<t, t>
#define p2(t, s) pair<t, s>
#define vp(t) v(p(t))

#define rep(i, n) for (int i=0,i##_len=((int)(n)); i<i##_len; ++i)
#define rep2(i, a, n) for (int i=((int)(a)),i##_len=((int)(n)); i<=i##_len; ++i)
#define repr(i, n) for (int i=((int)(n)-1); i>=0; --i)
#define rep2r(i, a, n) for (int i=((int)(n)),i##_len=((int)(a)); i>=i##_len; --i)

#define repi(itr, c) for (__typeof((c).begin()) itr=(c).begin(); itr!=(c).end(); ++itr)
#define repir(itr, c) for (__typeof((c).rbegin()) itr=(c).rbegin(); itr!=(c).rend(); ++itr)

#define sz(x) ((int)(x).size())
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()

#define SORT(v, n) sort(v, v+n);
#define VSORT(v) sort(v.begin(), v.end());
#define RSORT(x) sort(rall(x));
#define pb push_back
#define eb emplace_back

#define INF (1e9)
#define LINF (1e18)
#define PI (acos(-1))
#define EPS (1e-7)
#define DEPS (1e-10)

int main(){
    int n;
    cin >> n;
    v(set<int>) board(n*n, set<int>{1,2,3});
    set<p2(p2(int,set<int>),int)> cells;
    rep(i, n*n) cells.emplace(p2(int,set<int>){3,set<int>{1,2,3}},i);
    rep(i1, n*n) {
        int ai;
        cin >> ai;
        int bi = 0, ival = 0, jval = 0;
        repi(itr, cells) {
            const v(int) dy = { -1, 0, 1, 0 }, dx = { 0, 1, 0, -1 };
            auto sti = itr->first.second;
            int pos = itr->second;
            rep2(i2, 1, 3) {
                if (i2 == ai) continue;
                if (sti.find(i2) != sti.end()) {
                    int y = pos / n, x = pos % n;
                    bool ok = true;
                    rep(i, 4) {
                        int ny = y + dy[i], nx = x + dx[i];
                        if (ny<0||ny>=n||nx<0||nx>=n) continue;
                        auto bti = board[ny*n+nx];
                        if (bti.find(i2)!=bti.end() && sz(bti)<=2) ok = false; 
                        if (!ok) break;
                    }
                    if (ok) {
                        bi = i2;
                        ival = pos / n + 1;
                        jval = pos % n + 1;
                        break;
                    }
                } 
            }
            if (bi != 0) {
                rep(i, 4) {
                    int ny = (ival-1) + dy[i], nx = (jval-1) + dx[i];
                    if (ny<0||ny>=n||nx<0||nx>=n) continue;
                    auto bti = board[ny*n+nx];
                    if (bti.find(bi)!=bti.end()) bti.erase(bi);
                }
                board[pos].clear();
                cells.erase(itr);
                break;
            }
        }
        cout << bi << ' ' << ival << ' ' << jval << endl;
        cout.flush();
    }
    return 0;
}

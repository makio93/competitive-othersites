// 本番AC

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
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        v(string) cells(n);
        rep(i, n) cin >> cells[i];
        v(p(int)) marked(2, p(int){-1,-1});
        int mcnt = 0;
        rep(i, n) rep(j, n) {
            if (cells[i][j] == '*') {
                marked[mcnt] = { i, j };
                ++mcnt;
            }
        }
        v(p(int)) checked = marked;
        if (marked[0].first == marked[1].first) {
            if (marked[0].first+1<n) {
                rep(j, 2) checked[j].first++;
            }
            else {
                rep(j, 2) checked[j].first--;
            }
        }
        else if (marked[0].second == marked[1].second) {
            if (marked[0].second+1<n) {
                rep(j, 2) checked[j].second++;
            }
            else {
                rep(j, 2) checked[j].second--;
            }
        }
        else {
            rep(j, 2) checked[j].second = marked[1-j].second;
        }
        rep(j, 2) cells[checked[j].first][checked[j].second] = '*';
        rep(i, n) cout << cells[i] << endl;
    }
    return 0;
}

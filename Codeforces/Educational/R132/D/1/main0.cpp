// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, m, q;
    cin >> n >> m;
    vector<int> a(m);
    rep(i, m) cin >> a[i];
    vector<int> sids(m+1);
    int tl = 0;
    rep3(i, 1, m+1) {
        if (i > (1<<(tl+1))) ++tl;
        sids[i] = tl;
    }
    vector<vector<int>> st(m, vector<int>(tl+1));
    rep(i, m) st[i][0] = a[i];
    rep(i, tl) rep(j, m) st[j][i+1] = max(st[j][i], j+(1<<i)<m?st[j+(1<<i)][i]:0);
    cin >> q;
    rep(i, q) {
        int xs, ys, xf, yf, k;
        cin >> xs >> ys >> xf >> yf >> k;
        --xs; --ys; --xf; --yf;
        if (abs(xs-xf)%k!=0 || abs(ys-yf)%k!=0) {
            cout << "NO" << endl;
            continue;
        }
        if (ys > yf) {
            swap(ys, yf);
            swap(xs, xf);
        }
        int mval = max(st[ys][sids[yf-ys+1]], st[yf-(1<<sids[yf-ys+1])+1][sids[yf-ys+1]]);
        int add = (mval > xs) ? ((mval - xs) + k - 1) / k * k : 0;
        if (xs+add >= n) cout << "NO" << endl;
        else cout << "YES" << endl;
    }
    return 0;
}

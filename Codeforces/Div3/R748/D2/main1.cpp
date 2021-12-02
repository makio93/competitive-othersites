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

unordered_set<int> divisors(int val) {
    unordered_set<int> res;
    for (int i=1; i*i<=val; ++i) if (val%i == 0) { res.insert(i); res.insert(val/i); }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        int res = -1;
        rep(i, n) {
            int zcnt = 0;
            vector<int> d;
            rep(j, n) {
                if (a[j] == a[i]) ++zcnt;
                else if (a[j] > a[i]) d.push_back(a[j]-a[i]);
            }
            if (zcnt >= n/2) {
                res = max(res, INF);
                break;
            }
            unordered_map<int, int> dcnt;
            for (int di : d) for (int dj : divisors(di)) dcnt[dj]++;
            for (auto pi : dcnt) if (pi.second >= n/2-zcnt) res = max(res, pi.first);
        }
        cout << (res==INF ? -1 : res) << endl;
    }
    return 0;
}

// 学習1回目,自力AC

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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, k;
        cin >> n >> k;
        vector<int> a(n);
        rep(i, n) cin >> a[i];
        if (k == n) {
            cout << INF << endl;
            continue;
        }
        vector<int> alst = a;
        sort(all(alst));
        multiset<int, greater<int>> dst;
        multiset<int> ust;
        rep(i, n) {
            if (i < k) dst.insert(alst[i]*2);
            else ust.insert(alst[i]*2);
        }
        int res = 0;
        auto change = [&](int ai, int bi) -> void {
            if (dst.find(ai) != dst.end()) dst.erase(dst.find(ai));
            else ust.erase(ust.find(ai));
            if (!ust.empty() && bi>=*ust.begin()) ust.insert(bi);
            else dst.insert(bi);
            while ((int)(dst.size()) > k) {
                ust.insert(*dst.begin());
                dst.erase(dst.begin());
            }
            while ((int)(ust.size()) > n-k) {
                dst.insert(*ust.begin());
                ust.erase(ust.begin());
            }
        };
        rep(i, n-1) {
            change(a[i]*2, a[i]);
            change(a[i+1]*2, a[i+1]);
            res = max(res, min(INF, *ust.begin()));
            change(a[i], a[i]*2);
            change(a[i+1], a[i+1]*2);
        }
        cout << res << endl;
    }
    return 0;
}

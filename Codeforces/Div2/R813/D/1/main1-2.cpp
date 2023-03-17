// 学習1回目,解説AC2

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
        vector<pair<int, int>> atmp;
        rep(i, n) atmp.emplace_back(a[i], i);
        sort(all(atmp));
        rep(i, k-1) a[atmp[i].second] = INF;
        multiset<int> st1;
        multiset<int, greater<int>> st2;
        rep(i, n) st1.insert(a[i]*2);
        rep(i, n-1) st2.insert(min(a[i], a[i+1]));
        int res = 0;
        rep(i, n) {
            st1.erase(st1.find(a[i]*2));
            if (i-1 >= 0) st2.erase(st2.find(min(a[i-1], a[i])));
            if (i+1 < n) st2.erase(st2.find(min(a[i], a[i+1])));
            int ai = a[i];
            a[i] = INF;
            st1.insert(a[i]*2);
            if (i-1 >= 0) st2.insert(min(a[i-1], a[i]));
            if (i+1 < n) st2.insert(min(a[i], a[i+1]));
            res = max(res, min({ INF, *st2.begin(), *st1.begin() }));
            st1.erase(st1.find(a[i]*2));
            if (i-1 >= 0) st2.erase(st2.find(min(a[i-1], a[i])));
            if (i+1 < n) st2.erase(st2.find(min(a[i], a[i+1])));
            a[i] = ai;
            st1.insert(a[i]*2);
            if (i-1 >= 0) st2.insert(min(a[i-1], a[i]));
            if (i+1 < n) st2.insert(min(a[i], a[i+1]));
        }
        cout << res << endl;
    }
    return 0;
}

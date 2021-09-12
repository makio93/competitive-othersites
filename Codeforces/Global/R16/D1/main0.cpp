#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, T x=1) {
        for (i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, m;
        cin >> n >> m;
        vector<int> a(n*m);
        rep(i, n*m) cin >> a[i];
        vector<int> tvec = a;
        sort(all(tvec));
        tvec.erase(unique(all(tvec)), tvec.end());
        unordered_map<int, int> rval;
        rep(i, (int)(tvec.size())) rval[tvec[i]] = i+1;
        rep(i, n*m) a[i] = rval[a[i]];
        BIT<int> acnt(n*m+2);
        ll res = 0;
        rep(i, n*m) {
            res += acnt.sum(a[i]-1);
            acnt.add(a[i], 1);
        }
        cout << res << endl;
    }
    return 0;
}

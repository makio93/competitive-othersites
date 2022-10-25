// 解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, x;
    cin >> n >> x;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    vector<int> acnt(x);
    rep(i, n) if (a[i] < x) acnt[a[i]]++;
    rep3(i, 1, x) {
        if (i+1 < x) acnt[i+1] += acnt[i] / (i+1);
        acnt[i] %= (i+1);
    }
    bool ok = true;
    rep3(i, 1, x) if (acnt[i] != 0) {
        ok = false;
        break;
    }
    if (ok) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

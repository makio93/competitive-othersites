#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int next_val(int val) {
    int sval = 0, tval = val;
    rep(i, 3) {
        sval += tval % 10;
        tval /= 10;
    }
    return (val * 10 % 1000 + sval % 10);
}

int main() {
    vector<int> a(3);
    rep(i, 3) cin >> a[i];
    ll k;
    cin >> k;
    vector<int> memo(1000, -1);
    int val = a[0] % 10 * 100 + a[1] % 10 * 10 + a[2] % 10;
    ll rcnt = 3;
    int res = -1;
    memo[val] = (int)rcnt;
    while (rcnt <= k) {
        ++rcnt;
        val = next_val(val);
        if (memo[val] == -1) memo[val] = (int)rcnt;
        else {
            ll roop = (int)rcnt - memo[val];
            ll rest = k - rcnt;
            rest %= roop;
            ll tar = memo[val] + (int)rest;
            rep(i, 1000) if (memo[i] == (int)(tar)) {
                res = i % 10;
                break;
            }
        }
        if (rcnt == k) res = val % 10;
        if (res != -1) break;
    }
    if (res == -1) res = val % 10;
    cout << res << endl;
    return 0;
}

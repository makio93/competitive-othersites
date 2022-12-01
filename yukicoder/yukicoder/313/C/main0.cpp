#include <bits/stdc++.h>
using namespace std;

using ll = long long;
using ull = unsigned long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int n;
    cin >> n;
    vector<ull> a(n);
    rep(i, n) cin >> a[i];
    ull mi = ~0ULL;
    rep(i, n) mi &= ~a[i];
    ull xi = 1ULL;
    while ((mi&xi) == 0ULL) xi <<= 1;
    cout << xi << endl;
    return 0;
}

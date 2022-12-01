#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int a, b, c, d, m;
    cin >> a >> b >> c >> d >> m;
    int res = 0;
    rep3(i, a, b+1) rep3(j, c, d+1) res = max(res, (i+j)%m);
    cout << res << endl;
    return 0;
}

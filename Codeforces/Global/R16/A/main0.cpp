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
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n, s;
        cin >> n >> s;
        int ri = n - (n+1) / 2 + 1;
        int val = s / ri;
        cout << val << endl;
    }
    return 0;
}

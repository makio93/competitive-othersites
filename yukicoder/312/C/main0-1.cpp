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
    int n;
    cin >> n;
    vector<int> a(n);
    rep(i, n) cin >> a[i];
    int cnt = 0;
    rep(i, n) if (a[i] > 1) {
        int val = 0;
        int ai = a[i];
        for (int j=2; j*j<=ai; ++j) {
            while (ai%j == 0) {
                ai /= j;
                ++val;
            }
        }
        if (ai > 1) ++val;
        cnt ^= val;
    }
    if (cnt != 0) cout << "white" << endl;
    else cout << "black" << endl;
    return 0;
}

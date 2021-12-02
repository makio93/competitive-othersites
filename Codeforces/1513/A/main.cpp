#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main(){
    int t;
    cin >> t;
    rep(i1, t) {
        int n, k;
        cin >> n >> k;
        if ((n-1)/2 < k) {
            cout << -1 << endl;
            continue;
        }
        vector<int> a(n, -1);
        int now = n;
        for (int i=1; i<n; i+=2) {
            if (k <= 0) break;
            a[i] = now;
            --now; --k;
        }
        rep(i, n) if (a[i] == -1) {
            a[i] = now;
            --now;
        }
        rep(i, n) printf("%d%c", a[i], (i<n-1?' ':'\n'));
    }
    return 0;
}

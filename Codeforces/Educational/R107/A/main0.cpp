#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main(){
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<int> r(n);
        rep(i, n) cin >> r[i];
        int cnt = 0;
        rep(i, n) if (r[i] != 2) ++cnt;
        cout << cnt << endl;
    }
    return 0;
}

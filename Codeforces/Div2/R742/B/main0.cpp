#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const int MX = (int)(3e5) + 5;

int main() {
    int t0;
    cin >> t0;
    vector<int> xvals(MX+1);
    rep3(i, 1, MX+1) xvals[i] = xvals[i-1] ^ i;
    rep(i0, t0) {
        int a, b;
        cin >> a >> b;
        int xval = xvals[a-1] ^ b;
        if (xval == 0) cout << a << endl;
        else if (xval == a) cout << (a+2) << endl;
        else cout << (a+1) << endl;
    }
    return 0;
}

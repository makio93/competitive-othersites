#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番中AC

int main() {
    ll n;
    cin >> n;
    ll val = pow(n, 1.0/3.0);
    while (val*val*val > n) --val;
    while (val*val*val < n) ++val;
    if (val*val*val == n) cout << "Yes" << endl;
    else cout << "No" << endl;
    return 0;
}

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
    int n, q;
    cin >> n >> q;
    vector<int> lamps(n+1);
    int nval = 0;
    rep(i, q) {
        int li, ri;
        cin >> li >> ri;
        --li;
        rep3(j, li, ri) {
            nval += (1-lamps[j]) - lamps[j];
            lamps[j] = (1-lamps[j]);
        }
        cout << nval << endl;
    }
    return 0;
}

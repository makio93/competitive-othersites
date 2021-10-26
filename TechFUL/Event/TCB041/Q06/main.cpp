#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n >> q;
    vector<int> a(n);
    vector<ll> b(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    for (int i=0; i<n; ++i) cin >> b[i];
    ll c = 0;
    for (int i=0; i<q; ++i) {
        int qi;
        cin >> qi;
        if (qi == 1) {
            int ai, bi;
            cin >> ai >> bi;
            c += (1LL<<ai) * bi;
        }
        else if (qi == 2) {
            int ci, di;
            cin >> ci >> di;
            --ci;
            b[ci] += di;
        }
        else if (qi == 3) {
            int ei, fi;
            cin >> ei >> fi;
            --ei;
            ll xi = b[ei], yi = c / a[ei], si = min({(ll)fi, xi, yi});
            b[ei] -= si; c -= si * a[ei];
        }
        else {
            int bcnt = 0;
            for (int i=0; i<30; ++i) if ((c>>i) & 1) ++bcnt;
            bcnt += (c>>30);
            cout << bcnt << endl;
            c = 0;
        }
    }
    return 0;
}

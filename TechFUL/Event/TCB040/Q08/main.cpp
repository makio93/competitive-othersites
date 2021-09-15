#include <iostream>
#include <vector>
using namespace std;

using ll = long long;

int main() {
    int t;
    cin >> t;
    for (int i1=0; i1<t; ++i1) {
        ll l, r, n;
        cin >> l >> r >> n;
        if (n==1LL || l==0LL) {
            cout << "inf" << endl;
            continue;
        }
        vector<pair<ll, int>> plst;
        ll ntmp = n;
        for (ll i=2; i*i<=ntmp; ++i) if (ntmp%i == 0) {
            plst.emplace_back(i, 0);
            while (ntmp%i == 0) {
                ntmp /= i;
                plst.back().second++;
            }
        }
        if (ntmp > 1) { plst.emplace_back(ntmp, 1); }
        int plen = plst.size();
        vector<ll> rcnts(plen);
        for (int i=0; i<plen; ++i) {
            ll mtmp = 1;
            while (mtmp <= r/plst[i].first) {
                mtmp *= plst[i].first;
                ll mcnt = (ll)(1e18)+5;
                rcnts[i] += (r/mtmp - (l-1)/mtmp);
            }
        }
        ll res = (ll)(1e18) + 5;
        for (int i=0; i<plen; ++i) res = min(res, rcnts[i]/plst[i].second);
        cout << res << endl;
    }
    return 0;
}

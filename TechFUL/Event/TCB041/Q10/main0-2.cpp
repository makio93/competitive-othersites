#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// 本番WA2

const ll INF = (ll)(-1e18);

struct BIT {
    int n;
    pair<ll, ll> c;
    vector<pair<pair<ll, ll>, int>> d;
    BIT(int n=0, pair<ll, ll> c={1,1}) : n(n), c(c), d(n+1, make_pair(make_pair(INF,INF),-1)) {}
    void update(int i, pair<ll, ll> x) {
        pair<pair<ll, ll>, int> dx = { x, i };
        for (i++; i<=n; i+=i&-i) {
            d[i] = (d[i].second==-1||(d[i].second!=-1&&d[i].first.first*c.first+d[i].first.second*c.second<x.first*c.first+x.second*c.second)) ? dx : d[i];
        }
    }
    pair<pair<ll, ll>, int> query(int i) {
        pair<pair<ll, ll>, int> dx = make_pair(make_pair(INF, INF), -1);
        for (i++; i; i-=i&-i) {
            dx = (dx.second==-1||(dx.second!=-1&&d[i].first.first*c.first+d[i].first.second*c.second>dx.first.first*c.first+dx.first.second*c.second)) ? d[i] : dx;
        }
        return dx;
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i=0; i<n; ++i) cin >> x[i] >> y[i];
    vector<BIT> bt(4, BIT(n));
    for (int i=0; i<4; ++i) {
        pair<ll, ll> ci = { 1, 1 };
        if (i&1) ci.first *= -1;
        if ((i>>1)&1) ci.second *= -1;
        bt[i].c = ci;
    }
    for (int i=0; i<n; ++i) for (int j=0; j<4; ++j) bt[j].update(i, { x[i], y[i] });
    cin >> q;
    for (int i=0; i<q; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        ll res = INF;
        for (int j=0; j<4; ++j) {
            bt[j].c = { ai, bi };
            auto mval = bt[j].query(n-1);
            ll xi = x[mval.second], yi = y[mval.second];
            res = max(res, (xi*ai+yi*bi));
        }
        cout << res << endl;
    }
    return 0;
}

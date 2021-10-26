#include <iostream>
#include <vector>
using namespace std;
using ll = long long;

// 本番WA1

const ll INF = (ll)(-1e18);

struct BIT {
    int n;
    pair<ll, ll> c;
    vector<pair<pair<ll, ll>, int>> d;
    BIT(int n=0) : n(n), c({1,1}), d(n+1, make_pair(make_pair(INF,INF),-1)) {}
    void update(int i, pair<ll, ll> x) {
        pair<pair<ll, ll>, int> dx = { x, i };
        for (i++; i<=n; i+=i&-i) {
            d[i] = (d[i].first==make_pair(INF,INF)||d[i].first.first*c.first+d[i].first.second*c.second<x.first*c.first+x.second*c.second) ? dx : d[i];
        }
    }
    pair<pair<ll, ll>, int> query(int i) {
        pair<pair<ll, ll>, int> dx = make_pair(make_pair(INF, INF), -1);
        for (i++; i; i-=i&-i) {
            dx = (dx.first==make_pair(INF,INF)||d[i].first.first*c.first+d[i].first.second*c.second>dx.first.first*c.first+dx.first.second*c.second) ? d[i] : dx;
        }
        return dx;
    }
};

const vector<ll> mul = { 1, -1 };

int main() {
    int n, q;
    cin >> n;
    vector<ll> x(n), y(n);
    for (int i=0; i<n; ++i) cin >> x[i] >> y[i];
    vector<BIT> bt(4, BIT(n));
    for (int i=0; i<n; ++i) {
        auto xi = x[i], yi = y[i];
        for (int j=0; j<4; ++j) {
            xi *= mul[(j&1)];
            yi *= mul[((j>>1)&1)];
            bt[j].update(i, { xi, yi });
        }
    }
    cin >> q;
    for (int i=0; i<q; ++i) {
        ll ai, bi;
        cin >> ai >> bi;
        ll res = INF;
        for (int j=0; j<4; ++j) {
            bt[j].c = { ai, bi };
            auto mval = bt[j].query(n-1);
            ll xi = x[mval.second], yi = y[mval.second];
            res = max(res, xi*ai+yi*bi);
        }
        cout << res << endl;
    }
    return 0;
}

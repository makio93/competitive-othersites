#include <iostream>
#include <vector>
#include <unordered_set>
#include <unordered_map>
using namespace std;
using ll = long long;

const int INF = (ll)(1.2e18);

int main() {
    int n, m;
    cin >> n >> m;
    vector<unordered_set<int>> res(2);
    vector<unordered_set<int>> exl(2);
    vector<bool> exok(2, true), isno(2, false);
    for (int i=0; i<m; ++i) {
        int si;
        ll ti;
        cin >> si >> ti;
        vector<ll> bin(2);
        vector<unordered_map<int, ll>> xvals(2);
        ll zval = 0;
        for (int j=0; j<si; ++j) {
            int v1;
            cin >> v1;
            if (v1 == 1) {
                int v2;
                ll ai;
                cin >> v2 >> ai;
                if (v2 == 1) bin[1] += ai * 2;
                else bin[0] += ai * 2;
            }
            else {
                int xi;
                ll ai;
                cin >> xi >> ai;
                if (xi > 0) {
                    if (xi%2 == 1) {
                        xvals[1][xi] += ai * n;
                        exl[1].insert(xi);
                    }
                    else {
                        xvals[0][xi] += ai * n;
                        exl[0].insert(xi);
                    }
                }
                else {
                    zval += ai * n;
                }
            }
        }
        vector<unordered_set<int>> adds(2);
        for (int j1=0; j1<2; ++j1) {
            ll tval = ti - bin[j1];
            if (tval < 0) {
                isno[j1] = true;
            }
            if (tval > 0) exok[j1] = false;
            if (tval > 0) {
                for (auto pi : xvals[j1]) {
                    if (pi.second == tval) adds[j1].insert(pi.first);
                }
            }
            for (auto pi : xvals[1-j1]) {
                if (pi.second == ti) adds[j1].insert(pi.first);
            }
            if (zval == ti) adds[j1].insert(0);
            if (i == 0) res[j1] = adds[j1];
            else {
                unordered_set<int> nres;
                for (int aval : adds[j1]) if (res[j1].find(aval) != res[j1].end()) nres.insert(aval);
                swap(nres, res[j1]);
            }
        }
    }
    int ans = 0;
    for (int i=0; i<2; ++i) if (!isno[i]) {
        if (exok[i]) ans += n/2 - (int)(exl[i].size());
        else ans += res[i].size();
    }
    if (isno[0] && isno[1] && (res[0].find(0)!=res[0].end() || res[1].find(0)!=res[1].end())) ++ans;
    cout << ans << endl;
    return 0;
}

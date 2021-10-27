// 本番TLE

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <map>
using namespace std;
using ll = long long;

int main() {
    int n, q;
    cin >> n;
    vector<int> a(n);
    for (int i=0; i<n; ++i) cin >> a[i];
    unordered_map<int, vector<int>> acnt;
    for (int i=0; i<n; ++i) acnt[a[i]].push_back(i+1);
    map<int, int> aval2;
    vector<ll> aval1(n+1), sum1(n+1), vcnt1(n+1), scnt1(n+1);
    unordered_map<int, map<int, pair<ll, int>>> sum2;
    for (auto pi : acnt) {
        if ((int)(pi.second.size()) <= 2) {
            for (int aid : pi.second) {
                aval1[aid-1] = aid;
                vcnt1[aid-1]++;
            }
        }
        else {
            sum2[pi.first][0] = { 0, 0 };
            for (int aid : pi.second) {
                aval2[aid] = pi.first;
                sum2[pi.first][aid].first = aid;
            }
            int tcnt = 0;
            for (auto aitr=next(sum2[pi.first].begin()); aitr!=sum2[pi.first].end(); ++aitr) {
                ++tcnt;
                aitr->second.first += prev(aitr)->second.first;
                aitr->second.second = tcnt;
            }
        }
    }
    for (int i=0; i<n; ++i) {
        sum1[i+1] = sum1[i] + aval1[i];
        scnt1[i+1] = scnt1[i] + vcnt1[i];
    }
    cin >> q;
    for (int i=0; i<q; ++i) {
        int li, ri;
        cin >> li >> ri;
        ll xi = (sum1[ri] - sum1[li-1]) - (scnt1[ri] - scnt1[li-1]) * (li - 1);
        unordered_set<int> used;
        for (auto itr=aval2.lower_bound(li); itr!=aval2.lower_bound(ri+1); ++itr) {
            if (used.find(itr->second) != used.end()) continue;
            auto litr = sum2[itr->second].lower_bound(li), ritr = sum2[itr->second].lower_bound(ri+1);
            if (ritr != sum2[itr->second].begin()) {
                --ritr; --litr;
                ll txi = (ritr->second.first-litr->second.first) - (ritr->second.second-litr->second.second) * (li-1);
                if (txi > 0) xi += txi;
                if (ritr != sum2[itr->second].begin()) {
                    --ritr; ++litr;
                    ll txi2 = (ritr->second.first-litr->second.first) - (ritr->second.second-litr->second.second) * (li-1);
                    if (txi2 > 0) xi -= txi2;
                }
            }
            used.insert(itr->second);
        }
        cout << xi << endl;
    }
    return 0;
}

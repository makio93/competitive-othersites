// 本番AC

#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;

template<typename T>
struct BIT {
    int n;
    vector<T> d;
    BIT(int n=0) : n(n), d(n+1) {}
    void add(int i, T x=1) {
        for (i++; i<=n; i+=i&-i) {
            d[i] += x;
        }
    }
    T sum(int i) {
        T x = 0;
        for (i++; i; i-=i&-i) {
            x += d[i];
        }
        return x;
    }
    T sum(int l, int r) {
        return sum(r-1) - sum(l-1);
    }
};

int main() {
    int n, q;
    cin >> n;
    vector<int> l(n), r(n);
    for (int i=0; i<n; ++i) cin >> l[i] >> r[i];
    cin >> q;
    vector<int> a(q), b(q);
    for (int i=0; i<q; ++i) cin >> a[i] >> b[i];
    vector<pair<int, int>> clst;
    clst.emplace_back(0, 0);
    clst.emplace_back((int)(1e9)+5, 0);
    for (int i=0; i<n; ++i) {
        clst.emplace_back(l[i], 0);
        clst.emplace_back(r[i], 0);
        clst.emplace_back(r[i], 1);
    }
    for (int i=0; i<q; ++i) {
        clst.emplace_back(a[i], 0);
        clst.emplace_back(b[i], 0);
    }
    sort(clst.begin(), clst.end());
    clst.erase(unique(clst.begin(), clst.end()), clst.end());
    int clen = clst.size();
    map<pair<int, int>, int> rdic;
    for (int i=0; i<clen; ++i) rdic[clst[i]] = i;
    for (int i=0; i<n; ++i) {
        l[i] = rdic[{l[i],0}];
        r[i] = rdic[{r[i],1}];
    }
    for (int i=0; i<q; ++i) {
        a[i] = rdic[{a[i],0}];
        b[i] = rdic[{b[i],0}];
    }
    map<int, pair<vector<int>, vector<int>>> lrlst;
    lrlst[0].first = vector<int>(0);
    lrlst[0].second = vector<int>(0);
    for (int i=0; i<n; ++i) {
        lrlst[l[i]].first.push_back(i);
        lrlst[r[i]].second.push_back(i);
    }
    BIT<int> lids(clen+5);
    map<int, vector<int>> blst;
    for (int i=0; i<q; ++i) blst[b[i]].push_back(i);
    vector<int> ans(q);
    for (auto itr=lrlst.begin(); next(itr)!=lrlst.end(); ++itr) {
        auto nitr = next(itr);
        for (auto bitr=blst.lower_bound(itr->first); bitr!=blst.lower_bound(nitr->first); ++bitr) {
            for (int bi : bitr->second) ans[bi] += lids.sum(a[bi]);
        }
        if (!nitr->second.first.empty()) for (int li : nitr->second.first) lids.add(l[li], 1);
        if (!nitr->second.second.empty()) for (int li : nitr->second.second) lids.add(l[li], -1);
    }
    for (int i=0; i<q; ++i) cout << ans[i] << endl;
    return 0;
}

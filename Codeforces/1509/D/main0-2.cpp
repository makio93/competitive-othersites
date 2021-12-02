// ヒントだけ見て実装

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

int main() {
    int t;
    cin >> t;
    rep(i1, t) {
        int n;
        cin >> n;
        vector<string> b(3);
        rep(i, 3) cin >> b[i];
        vector<int> zcnt(3);
        vector<pair<int, int>> id = { { 0, 1 }, { 0, 2 }, { 1, 2 } };
        rep(i, 3) rep(j, 2*n) if (b[i][j] == '0') zcnt[i]++;
        pair<int, int> mid = { (int)(1e9), -1 };
        rep(i, 3) mid = min(mid, pair<int,int>{ abs(zcnt[id[i].first]-zcnt[id[i].second]), i });
        pair<int, int> tid = id[mid.second];
        int ccnt = max(zcnt[tid.first], zcnt[tid.second]);
        char rch = '0', rch2 = '1';
        deque<pair<char, int>> rstr(ccnt, pair<char, int>(rch, 1));
        auto ritr = rstr.begin();
        pair<int, int> ipos = { 0, 0 };
        while (ipos.first<2*n && b[tid.first][ipos.first]!=rch) ++ipos.first;
        while (ipos.second<2*n && b[tid.second][ipos.second]!=rch) ++ipos.second;
        if (ipos.first>0 || ipos.second>0) {
            ritr = rstr.insert(ritr, pair<char, int>{ rch2, max(ipos.first, ipos.second) });
            ++ritr;
        }
        while (ritr != rstr.end()) {
            ++ritr;
            pair<int, int> lcnt = { 0, 0 };
            if (ipos.first < 2*n) {
                ipos.first++;
                while (ipos.first<2*n && b[tid.first][ipos.first]!=rch) { ++lcnt.first; ++ipos.first; }; 
            }
            if (ipos.second < 2*n) {
                ipos.second++;
                while (ipos.second<2*n && b[tid.second][ipos.second]!=rch) { ++lcnt.second; ++ipos.second; };
            }
            if (max(lcnt.first, lcnt.second) > 0) {
                ritr = rstr.insert(ritr, pair<char, int>{ rch2, max(lcnt.first, lcnt.second) });
                ++ritr;
            }
        }
        string res;
        rep(i, (int)(rstr.size())) res += string(rstr[i].second, rstr[i].first);
        cout << res << endl;
    }
    return 0;
}

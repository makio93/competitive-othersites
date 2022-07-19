// 解説AC

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
        vector<int> zcnt(3), ocnt(3);
        vector<pair<int, int>> id = { { 0, 1 }, { 0, 2 }, { 1, 2 } };
        rep(i, 3) rep(j, 2*n) if (b[i][j] == '0') zcnt[i]++;
        rep(i, 3) rep(j, 2*n) if (b[i][j] == '1') ocnt[i]++;
        pair<int, int> mid0 = { 0, -1 }, mid1 = { 0, -1 };
        rep(i, 3) mid0 = max(mid0, pair<int,int>{ { min(zcnt[id[i].first], zcnt[id[i].second]) }, i });
        rep(i, 3) mid1 = max(mid1, pair<int,int>{ { min(ocnt[id[i].first], ocnt[id[i].second]) }, i });
        int ccnt = max(zcnt[id[mid0.second].first], zcnt[id[mid0.second].second]);
        pair<int, int> tid = id[mid0.second];
        char rch = '0', rch2 = '1';
        if (mid0.first < mid1.first) {
            ccnt = max(ocnt[id[mid1.second].first], ocnt[id[mid1.second].second]);;
            tid = id[mid1.second];
            swap(rch, rch2);
        }
        pair<int, int> ipos = { 0, 0 };
        while (ipos.first<2*n && b[tid.first][ipos.first]!=rch) ++ipos.first;
        while (ipos.second<2*n && b[tid.second][ipos.second]!=rch) ++ipos.second;
        string res;
        if (ipos.first>0 || ipos.second>0) {
            res += string(max(ipos.first, ipos.second), rch2);
        }
        rep(i, ccnt) {
            res += string(1, rch);
            pair<int, int> lcnt = { 0, 0 };
            if (ipos.first < 2*n) {
                ipos.first++;
                while (ipos.first<2*n && b[tid.first][ipos.first]!=rch) { ++lcnt.first; ++ipos.first; } 
            }
            if (ipos.second < 2*n) {
                ipos.second++;
                while (ipos.second<2*n && b[tid.second][ipos.second]!=rch) { ++lcnt.second; ++ipos.second; }
            }
            if (max(lcnt.first, lcnt.second) > 0) {
                res += string(max(lcnt.first, lcnt.second), rch2);
            }
        }
        cout << res << endl;
    }
    return 0;
}

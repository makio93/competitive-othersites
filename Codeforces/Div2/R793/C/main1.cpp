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
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        map<int, int> acnt;
        rep(i, n) {
            int ai;
            cin >> ai;
            acnt[ai]++;
        }
        int si = 0, di = 0;
        for (auto& [vi, ci] : acnt) {
            if (ci >= 2) ++di;
            else ++si;
        }
        cout << (di+(si+1)/2) << endl;
    }
    return 0;
}

// 学習1回目,自力AC

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
        string s;
        cin >> n >> s;
        if (s==string(n,'0') || count(all(s),'1')%2==1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            vector<pair<int, int>> res;
            if (s == string(n, '1')) rep3(i, 1, n) res.emplace_back(1, i+1);
            else {
                s += s;
                int zid = -1;
                rep(i, n*2) {
                    if (zid==-1 && s[i]=='1') zid = -2;
                    else if (zid==-2 && s[i]=='0') {
                        zid = i;
                        break;
                    }
                }
                if (zid >= n) zid -= n;
                int pid = zid;
                while (pid < zid+n) {
                    if (pid != zid) res.emplace_back(zid+1, (pid)%n+1);
                    while (pid<zid+n && s[pid]=='0') {
                        res.emplace_back((pid)%n+1, (pid+1)%n+1);
                        ++pid;
                    }
                    ++pid;
                }
            }
            int m = res.size();
            rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
        }
    }
    return 0;
}

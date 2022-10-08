// 学習1回目,解説AC

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
        int bcnt = count(all(s), '1');
        if (bcnt==0 || bcnt%2==1) cout << "NO" << endl;
        else {
            cout << "YES" << endl;
            vector<pair<int, int>> res;
            int sid = 0;
            while (s[sid] != '1') ++sid;
            ++sid;
            int pid = sid + 1;
            while (pid < sid+n) {
                res.emplace_back(sid%n+1, pid%n+1);
                int tid = pid + 1;
                while (tid<sid+n && s[(tid-1)%n]!='1') {
                    res.emplace_back((tid-1)%n+1, tid%n+1);
                    ++tid;
                }
                pid = tid;
            }
            int m = res.size();
            rep(i, m) cout << res[i].first << ' ' << res[i].second << endl;
        }
    }
    return 0;
}

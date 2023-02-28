// 学習1回目,解説AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int t0;
    cin >> t0;
    rep(i0, t0) {
        string s;
        cin >> s;
        int n = s.length();
        vector<int> qids;
        int lc = n / 2, rc = n / 2;
        rep(i, n) {
            if (s[i] == '(') --lc;
            else if (s[i] == ')') --rc;
            else qids.push_back(i);
        }
        int ql = qids.size();
        rep(i, ql) {
            if (i < lc) s[qids[i]] = '(';
            else s[qids[i]] = ')';
        }
        bool ok = true;
        if (lc>0 && rc>0) {
            ok = false;
            swap(s[qids[lc-1]], s[qids[lc]]);
            int cnt = 0;
            rep(i, n) {
                if (s[i] == '(') ++cnt;
                else --cnt;
                if (cnt < 0) ok = true;
            }
        }
        if (ok) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

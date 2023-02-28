// 学習1回目,自力AC

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
        if (n%2 == 1) {
            cout << "NO" << endl;
            continue;
        }
        int qcnt = count(all(s), '?');
        vector<int> bcnt(n+1);
        rep(i, n) {
            if (s[i] != ')') bcnt[i+1] = bcnt[i] + 1;
            else bcnt[i+1] = bcnt[i] - 1;
        }
        int lval = *min_element(all(bcnt));
        if (lval < 0) {
            cout << "NO" << endl;
            continue;
        }
        if (qcnt == 0) {
            cout << (bcnt[n]==0 ? "YES" : "NO") << endl;
            continue;
        }
        int tcnt = bcnt[n] / 2;
        if (tcnt > qcnt) {
            cout << "NO" << endl;
            continue;
        }
        vector<bool> negs(n+1);
        int ri = -1, li = -1;
        if (tcnt == 0) ri = n;
        repr(i, n) {
            if (s[i] != '?') continue;
            if (ri == -1) {
                negs[i] = true;
                --tcnt;
                if (tcnt == 0) ri = i;
            }
            else {
                li = i;
                break;
            }
        }
        rep(i, n) {
            if (s[i] == '?') bcnt[i+1] = bcnt[i] + (negs[i] ? -1 : 1);
            else if (s[i] == '(') bcnt[i+1] = bcnt[i] + 1;
            else bcnt[i+1] = bcnt[i] - 1;
        }
        lval = *min_element(all(bcnt));
        if (li == -1) {
            cout << (lval>=0 ? "YES" : "NO") << endl;
            continue;
        }
        int tval = *min_element(bcnt.begin()+li+1, bcnt.begin()+ri+1);
        if (lval>=0 && tval<2) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}

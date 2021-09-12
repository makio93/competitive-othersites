#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

const vector<string> tar = { "00", "11" };

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        vector<string> table(2);
        rep(i, 2) cin >> table[i];
        int id = 0, res = 0;
        while (id < n) {
            string ci = (string)("") + table[0][id] + table[1][id];
            bool same = false, same2 = false;
            int jid = -1;
            rep(j, 2) if (ci == tar[j]) {
                same = true;
                jid = j;
                if (id+1 < n) {
                    string ci2 = (string)("") + table[0][id+1] + table[1][id+1];
                    int jval = -1;
                    rep(j2, 2) if (ci2 == tar[j2]) jval = j2;
                    if (jval!=-1 && j!=jval) {
                        res += 2;
                        id += 2;
                        same2 = true;
                    }
                }
                if (same2) break;
            }
            if (same2) continue;
            if (same) res += (jid == 0) ? 1 : 0;
            else res += 2;
            ++id;
        }
        cout << res << endl;
    }
    return 0;
}

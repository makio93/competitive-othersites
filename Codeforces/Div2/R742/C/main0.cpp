#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番AC

int main() {
    int t0;
    cin >> t0;
    rep(i0, t0) {
        int n;
        cin >> n;
        string nstr = to_string(n);
        int nlen = nstr.length();
        ll res = 0;
        vector<int> star(nlen);
        rep(i, nlen) star[i] = nstr[nlen-i-1] - '0';
        if (nlen-2 <= 0) {
            ll sum = 1;
            rep(j, nlen) {
                int lval = 0, rval = 0;
                if (star[j] <= 9) { rval = star[j]; }
                else { lval = star[j] - 9; rval = star[j] - lval; }
                sum *= (rval - lval + 1);
            }
            res += sum;
        }
        else {
            rep(i, (1<<(nlen-2))) {
                ll sum = 1;
                vector<int> tar = star;
                rep(j, nlen-2) if (((i>>j)&1) == 1) {
                    tar[j] += 10;
                    tar[j+2]--;
                }
                bool ok = true;
                rep(j, nlen) if (tar[j]<0 || tar[j]>18) ok = false;
                if (!ok) continue;
                rep(j, nlen) {
                    int lval = 0, rval = 0;
                    if (tar[j] <= 9) { rval = tar[j]; }
                    else { lval = tar[j] - 9; rval = tar[j] - lval; }
                    sum *= (rval - lval + 1);
                }
                res += sum;
            }
        }
        res -= 2;
        cout << res << endl;
    }
    return 0;
}

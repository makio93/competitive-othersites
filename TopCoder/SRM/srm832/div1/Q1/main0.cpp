// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class CastleGuard {
public:
    vector<ll> walk(int N, int R, vector<int> commands) {
        vector<ll> adds(N);
        int m = commands.size(), vi = 0;
        rep(i, m) {
            int p = abs(commands[i]) / N, r = abs(commands[i]) % N;
            rep(j, N) adds[j] += p;
            if (commands[i] >= 0) {
                if (vi+r < N) {
                    rep3(j, vi+1, vi+r+1) adds[j]++;
                }
                else {
                    rep3(j, vi+1, N) adds[j]++;
                    int ri = vi + r - (N-1);
                    rep(j, ri) adds[j]++;
                }
                vi = (vi+r) % N;
            }
            else {
                if (vi-r >= 0) {
                    rep3(j, vi-r, vi) adds[j]++;
                }
                else {
                    rep(j, vi) adds[j]++;
                    int ri = abs(vi-r);
                    rep3(j, N-ri, N) adds[j]++;
                }
                vi = (vi-r+N) % N;
            }
        }
        int len = -1, nid = 0;
        vector<int> mul(N);
        rep(i, R) {
            mul[nid]++;
            nid = (nid + vi) % N;
            if (nid == 0) {
                len = i + 1;
                break;
            }
        }
        if (len != -1) {
            int pval = R / len, rval = R % len;
            rep(i, N) mul[i] *= pval;
            nid = 0;
            rep(i, rval) {
                mul[nid]++;
                nid = (nid + vi) % N;
            }
        }
        vector<ll> res(N);
        res[0] = 1;
        rep(i, N) {
            rep(j, N) {
                res[(i+j)%N] += (ll)mul[i] * adds[j];
            }
        }
        return res;
    }
};

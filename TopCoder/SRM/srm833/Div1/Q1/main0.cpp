// 本番作成

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
class Never3Steps {
public:
    int count(int X, int Y) {
        if (X==0 && Y==0) return 1;
        vector<vector<ll>> csub(X+1, vector<ll>(Y+2)), rsub(Y+1, vector<ll>(X+2));
        vector<vector<ll>> rdp(Y+1, vector<ll>(X+1)), cdp(Y+1, vector<ll>(X+1));
        rdp[0][0] = cdp[0][0] = 1;
        rep(i, Y+1) rep(j, X+1) {
            rdp[i][j] = (rdp[i][j] + rsub[i][j]) % mod;
            cdp[i][j] = (cdp[i][j] + csub[j][i]) % mod;
            csub[j][i+1] = (csub[j][i+1] + csub[j][i]) % mod;
            rsub[i][j+1] = (rsub[i][j+1] + rsub[i][j]) % mod;
            csub[j][i] = rsub[i][j] = 0;
            rsub[i][j+1] = (rsub[i][j+1] + cdp[i][j]) % mod;
            rsub[i][min(X+1,j+3)] = (rsub[i][min(X+1,j+3)] - cdp[i][j] + mod) % mod;
            rsub[i][min(X+1,j+4)] = (rsub[i][min(X+1,j+4)] + cdp[i][j]) % mod;
            rsub[i][X+1] = (rsub[i][X+1] - cdp[i][j] + mod) % mod;
            csub[j][i+1] = (csub[j][i+1] + rdp[i][j]) % mod;
            csub[j][min(Y+1,i+3)] = (csub[j][min(Y+1,i+3)] - rdp[i][j] + mod) % mod;
            csub[j][min(Y+1,i+4)] = (csub[j][min(Y+1,i+4)] + rdp[i][j]) % mod;
            csub[j][Y+1] = (csub[j][Y+1] - rdp[i][j] + mod) % mod;
        }
        return (int)((rdp[Y][X]+cdp[Y][X]) % mod);
    }
};

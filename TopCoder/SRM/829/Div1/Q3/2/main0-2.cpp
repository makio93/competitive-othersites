// 学習2回目,自力AC2

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
class UpdownNumbers {
public:
    int count(int D, int S) {
        vector<vector<int>> ito(1<<10, vector<int>(10)), dto(1<<10, vector<int>(10));
        rep3(i, 1, 1<<10) {
            vector<int> flst, tlst;
            rep(j, 10) if (i&(1<<j)) flst.push_back(j);
            rep(j, 10) {
                tlst = flst;
                int flen = flst.size(), id = flen;
                rep(j2, flen) {
                    if (flst[j2] == j) {
                        id = -1;
                        break;
                    }
                    if (flst[j2] > j) {
                        id = j2;
                        break;
                    }
                }
                if (id!=-1 && id<flen) tlst[id] = j;
                else if (id == flen) tlst.push_back(j);
                int tlen = tlst.size();
                rep(j2, tlen) ito[i][j] |= 1<<(tlst[j2]);
            }
        }
        rep3(i, 1, 1<<10) {
            vector<int> flst, tlst;
            repr(j, 10) if (i&(1<<j)) flst.push_back(j);
            rep(j, 10) {
                tlst = flst;
                int flen = flst.size(), id = flen;
                rep(j2, flen) {
                    if (flst[j2] == j) {
                        id = -1;
                        break;
                    }
                    if (flst[j2] < j) {
                        id = j2;
                        break;
                    }
                }
                if (id!=-1 && id<flen) tlst[id] = j;
                else if (id == flen) tlst.push_back(j);
                int tlen = tlst.size();
                rep(j2, tlen) dto[i][j] |= 1<<(tlst[j2]);
            }
        }
        vector<int> dp(1<<20), ndp;
        vector<bool> used(1<<20), nused;
        rep3(i, 1, 10) {
            dp[(1<<i)*(1<<10)+(1<<i)] = 1;
            used[(1<<i)*(1<<10)+(1<<i)] = true;
        }
        rep(i, D-1) {
            ndp.assign(1<<20, 0);
            nused.assign(1<<20, false);
            rep3(j1, 1, 1<<10) rep3(j2, 1, 1<<10) if (used[j1*(1<<10)+j2]) {
                rep(k, 10) {
                    ndp[ito[j1][k]*(1<<10)+dto[j2][k]] = (ndp[ito[j1][k]*(1<<10)+dto[j2][k]] + dp[j1*(1<<10)+j2]) % mod;
                    nused[ito[j1][k]*(1<<10)+dto[j2][k]] = true;
                }
            }
            swap(ndp, dp);
            swap(nused, used);
        }
        int res = 0;
        rep3(i, 1, 1<<10) {
            if (__builtin_popcount(i) < S) continue;
            rep3(j, 1, 1<<10) if (used[i*(1<<10)+j]) {
                if (__builtin_popcount(j) < S) continue;
                res = (res + dp[i*(1<<10)+j]) % mod;
            }
        }
        return res;
    }
};

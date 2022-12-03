// 自力WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class SmoothMultiples {
public:
    ll count(int K, ll A, ll B, ll C) {
        vector<int> atar, btar;
        while (B) {
            btar.push_back(B%10);
            B /= 10;
        }
        --A;
        while (A) {
            atar.push_back(A%10);
            A /= 10;
        }
        int len = (int)max(atar.size(), btar.size()) + 1;
        while ((int)(atar.size()) < len) atar.push_back(0);
        while ((int)(btar.size()) < len) btar.push_back(0);
        reverse(all(atar));
        reverse(all(btar));
        auto calc = [&](auto calc, vector<int>& tar, vector<int>& nvals, bool zero=true, bool upper=true, int di=0) -> ll {
            if (di == len) {
                ll val = 0;
                rep(i, len) {
                    val *= 10;
                    val += nvals[i];
                }
                if (val%C == 0) return 1;
                else return 0;
            }
            ll rval = 0;
            if (zero) {
                rep(i, 10) {
                    if (upper && i>tar[di]) break;
                    nvals[di] = i;
                    if (i == 0) rval += calc(calc, tar, nvals, true, upper&&(i==tar[di]), di+1);
                    else rval += calc(calc, tar, nvals, false, upper&&(i==tar[di]), di+1);
                }
            }
            else {
                rep(i, 10) {
                    if (upper && i>tar[di]) break;
                    if (abs(i-nvals[di-1]) > K) continue;
                    nvals[di] = i;
                    rval += calc(calc, tar, nvals, false, upper&&(i==tar[di]), di+1);
                }
            }
            return rval;
        };
        vector<int> btmp(len, -1), atmp(len, -1);
        ll res = calc(calc, btar, btmp) - calc(calc, atar, atmp);
        return res;
    }
};

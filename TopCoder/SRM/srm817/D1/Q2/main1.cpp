#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 解説実装,未完成(バグあり)

const ll INF = (ll)(1e18) + 2;
class IntrospectiveNumbers {
    vector<vector<ll>> choose;
public:
	string nth(ll index) {
        choose = vector<vector<ll>>(46, vector<ll>(46));
        choose[0][0] = 1;
        rep3(i, 1, 46) rep(j, i+1) {
            if (j==0 || j==i) choose[i][j] = 1;
            else choose[i][j] = min(INF, choose[i-1][j-1]+choose[i-1][j]);
        }
        vector<ll> lcnt(46);
        for (int i=2; i<(1<<10); i+=2) {
            int len = 0;
            vector<int> nlst;
            rep3(j, 1, 10) if ((i>>j)&1) {
                len += j;
                nlst.push_back(j);
            }
            int rval = len;
            ll lval = 1;
            for (int nl : nlst) {
                if (lval > INF/choose[rval][nl]) lval = INF;
                else lval = min(INF, lval*choose[rval][nl]);
                rval -= nl;
            }
            lcnt[len] = min(INF, lcnt[len]+lval);
        }
        int tlen = 0;
        rep3(i, 1, 46) {
            if (index < lcnt[i]) {
                tlen = i;
                break;
            }
            else index -= lcnt[i];
        }
        vector<int> res(tlen);
        rep(i, tlen) {
            res[i] = 1;
            while (res[i] <= 9) {
                ll rcnt0 = 0;
                vector<int> pcnt(10);
                rep(j, i+1) pcnt[res[j]]++;
                bool ok = true;
                int psum = 0;
                rep3(j, 1, 10) if (pcnt[j] > 0) {
                    if (pcnt[j] > j) { ok = false; break; }
                    psum += j - pcnt[j];
                }
                if (ok && psum<=tlen-(i+1)) {
                    ll rcnt1 = 1;
                    int len = tlen - (i+1);
                    rep3(j, 1, 10) if (pcnt[j] > 0) {
                        if (rcnt1 > INF/choose[len][j-pcnt[j]]) rcnt1 = INF;
                        else rcnt1 = min(INF, rcnt1*choose[len][j-pcnt[j]]);
                        len -= j - pcnt[j];
                    }
                    vector<int> rvals;
                    rep3(j, 1, 10) if (pcnt[j] == 0) rvals.push_back(j);
                    int rlen = rvals.size(), len2 = len;
                    rep(j, (1<<rlen)) {
                        vector<int> used;
                        int rsum = 0;
                        rep(j2, rlen) if ((j>>j2)&1) {
                            used.push_back(rvals[j2]);
                            rsum += rvals[j2];
                        }
                        if (rsum != len2) continue;
                        ll rcnt2 = 1;
                        for (int uval : used) {
                            if (rcnt2 > INF/choose[len2][uval]) rcnt2 = INF;
                            else rcnt2 = min(INF, rcnt2*choose[len2][uval]);
                            len2 -= uval;
                        }
                        rcnt0 += rcnt2;
                    }
                    if (rcnt0 > INF/rcnt1) rcnt0 = INF;
                    else rcnt0 = min(INF, rcnt0*rcnt1);
                }
                if (index < rcnt0) break;
                index -= rcnt0;
                res[i]++;
            }
        }
        string sres;
        for (int val : res) sres += (char)(val+'0');
        return sres;
    }
};

// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class LooRollPyramid {
public:
    vector<int> countMissing(int Q, vector<int> A, vector<ll> B) {
        vector<int> res;
        rep(i, Q) {
            if (B[i] == 0LL) {
                res.push_back(0);
                continue;
            }
            ll l = 0, r = A[i] + 1;
            while (r-l > 1) {
                ll c = (l+r+1) / 2;
                ll bcnt = ((ll)A[i] * 2 - c + 1) * c / 2;
                if (bcnt >= B[i]) r = c;
                else l = c;
            }
            ll ci = (A[i] * 2 - r + 1) * r / 2 - B[i];
            res.push_back((int)(ci));
        }
        return res;
    }
};

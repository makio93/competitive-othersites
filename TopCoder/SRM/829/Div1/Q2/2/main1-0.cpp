// 学習2回目,自力AC(ヒント有)

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;

class QuestionOrder {
public:
    int maxExpProfit(vector<int> A, vector<int> P) {
        int n = A.size();
        vector<int> ord(n);
        iota(all(ord), 0);
        auto calc = [&](int id) -> double {
            return A[ord[id]] * P[ord[id]] / 100.0 * P[ord[id+1]] / 100.0 + A[ord[id+1]] * P[ord[id+1]] / 100.0;
        };
        rep3r(i, 1, n) rep(j, i) {
            double fval = calc(j);
            swap(ord[j], ord[j+1]);
            double tval = calc(j);
            if (fval > tval) swap(ord[j], ord[j+1]);
        }
        ll res = 0;
        rep(i, n) {
            ll val = A[ord[i]];
            rep(j, n) {
                if (j < i) val = val * 100 % mod;
                else val = val * P[ord[j]] % mod;
            }
            res = (res + val) % mod;
        }
        return (int)res;
    }
};

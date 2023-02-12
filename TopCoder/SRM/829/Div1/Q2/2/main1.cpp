// 学習2回目,解説AC

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
        auto comp = [&](int id) -> bool {
            return (ll)A[id] * P[id] * (100 - P[id+1]) > (ll)A[id+1] * P[id+1] * (100 - P[id]);
        };
        rep(i, n) rep(j, n-1) if (comp(j)) {
            swap(A[j], A[j+1]);
            swap(P[j], P[j+1]);
        }
        ll res = 0, psum = 1;
        repr(i, n) {
            res = res * 100 % mod;
            psum = psum * P[i] % mod;
            res = (res + psum * A[i]) % mod;
        }
        return (int)res;
    }
};

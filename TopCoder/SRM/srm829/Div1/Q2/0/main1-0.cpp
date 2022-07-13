// 解説AC

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
        sort(all(ord), [&](int a, int b) { return A[a]*P[a]*(100-P[b]) < A[b]*P[b]*(100-P[a]); });
        ll res = 0, pmul = 1;
        repr(i, n) {
            pmul = pmul * P[ord[i]] % mod;
            res = (res * 100 + A[ord[i]] * pmul) % mod;
        }
        return (int)res;
    }
};

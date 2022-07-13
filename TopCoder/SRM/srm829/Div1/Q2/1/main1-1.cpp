// 復習1回目,解説AC1

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
        rep(i, n) rep(j, n-1) if (A[j]*P[j]*(100-P[j+1]) > A[j+1]*P[j+1]*(100-P[j])) swap(A[j], A[j+1]), swap(P[j], P[j+1]);
        ll res = 0, pval = 1;
        repr(i, n) {
            pval = pval * P[i] % mod;
            res = (res * 100 + A[i] * pval) % mod;
        }
        return (int)res;
    }
};

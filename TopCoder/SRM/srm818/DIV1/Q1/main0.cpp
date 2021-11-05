// 本番解答

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class MedianSegments {
public:
    ll count(int N, int K, vector<int> Aprefix, int M) {
        vector<ll> A(N);
        int L = Aprefix.size();
        rep(i, L) A[i] = Aprefix[i];
        ll state = Aprefix[L-1];
        rep3(i, L, N) {
            state = (state * 1103515245LL + 12345) % (1LL<<31);
            A[i] = state % (ll)M;
        }
        vector<int> sub(N+1);
        rep3(i, 1, N+1) sub[i] = (A[i-1] > A[K]) ? (sub[i-1]+1) : (A[i-1] < A[K]) ? (sub[i-1]-1) : sub[i-1];
        vector<map<int, int>> mcnts(2);
        rep(i, K+1) mcnts[i%2][sub[i]]++;
        ll res = 0;
        rep3(i, K+1, N+1) res += mcnts[(i+1)%2][sub[i]];
        return res;
    }
};

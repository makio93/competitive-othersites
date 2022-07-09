// 本番作成

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (1LL<<31);
class FroggerAndNets {
public:
    int jump(string stones, int C, int minW, int seed) {
        ll state = seed;
        int N = stones.length(), maxW = N - 1;
        vector<int> L(C), R(C);
        rep(i, C) {
            state = (state * 1103515245 + 12345) % mod;
            ll w = minW + (state % (maxW - minW + 1));
            state = (state * 1103515245 + 12345) % mod;
            L[i] = (int)(state % (N - w));
            R[i] = (int)(L[i] + w);
        }
        vector<int> sids;
        sids.push_back(-1);
        rep(i, N) if (stones[i] == 'O') sids.push_back(i);
        sids.push_back(N);
        vector<ll> dp(2);
        int lid = *lower_bound(all(sids), L[0]), rid = *prev(upper_bound(all(sids), R[0]));
        if (lid>R[0] && rid<L[0]) return -1;
        rep3(i, 1, C) {
            int tlid = *lower_bound(all(sids), L[i]), trid = *prev(upper_bound(all(sids), R[i]));
            if (tlid>R[i] && trid<L[i]) return -1;
            vector<ll> ndp(2);
            ndp[0] = max(dp[0]+abs(tlid-lid), dp[1]+abs(tlid-rid));
            ndp[1] = max(dp[0]+abs(trid-lid), dp[1]+abs(trid-rid));
            swap(dp, ndp);
            lid = tlid; rid = trid;
        }
        return (int)max(dp[0], dp[1]);
    }
};

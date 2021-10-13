// 解説AC2,O(N)解

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class StepLeapSurviveTraps {
public:
    ll minDamage(int N, int J, int seed, int M) {
        vector<ll> T(N+1);
        ll state = seed;
        rep3(i, 1, N+1) {
            state = (state * 1103515245LL + 12345) % (1LL<<31);
            T[i] = 1 + state % (ll)M;
        }
        vector<ll> dp(N+1);
        dp[0] = T[0];
        deque<pair<ll, int>> tvals;
        tvals.emplace_back(dp[0], 0);
        rep3(i, 1, N+1) {
            if (i-J-1 >= 0) { if (tvals.front().second == i-J-1) tvals.pop_front(); }
            dp[i] = tvals.front().first + T[i];
            while (!tvals.empty() && tvals.back().first>=dp[i]) tvals.pop_back();
            tvals.emplace_back(dp[i], i);
        }
        return dp[N];
    }
};

// 解説AC1,O(NlogN)解

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
        map<ll, int> tvals;
        tvals[dp[0]]++;
        rep3(i, 1, N+1) {
            if (i-J-1 >= 0) {
                tvals[dp[i-J-1]]--;
                if (tvals[dp[i-J-1]] == 0) tvals.erase(dp[i-J-1]);
            }
            dp[i] = tvals.begin()->first + T[i];
            tvals[dp[i]]++;
        }
        return dp[N];
    }
};

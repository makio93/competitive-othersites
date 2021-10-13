// 解説AC2,O(N)解,deque

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
        deque<ll> tvals; // '>='で書きたければpair<ll, int>型で持つ
        tvals.push_back(dp[0]);
        rep3(i, 1, N+1) {
            if (i-J-1 >= 0) { if (dp[i-J-1] == tvals.front()) tvals.pop_front(); }
            dp[i] = tvals.front() + T[i];
            while (!tvals.empty() && tvals.back()>dp[i]) tvals.pop_back(); // '>='にするとWAになる
            tvals.push_back(dp[i]);
        }
        return dp[N];
    }
};

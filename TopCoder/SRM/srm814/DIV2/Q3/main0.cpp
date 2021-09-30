// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class StepLeapSurviveTraps {
    ll INF = (ll)(1e17);
public:
    ll minDamage(int N, int J, int seed, int M) {
        vector<ll> T(N+1);
        ll state = seed;
        rep3(i, 1, N+1) {
            state = (state * 1103515245LL + 12345) % (1LL<<31);
            T[i] = 1 + state % (ll)M;
        }
        vector<ll> dist(N+1, INF);
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<pair<ll, int>>> que;
        dist[0] = 0;
        que.emplace(0, 0);
        while (!que.empty()) {
            auto pi = que.top(); que.pop();
            ll di = pi.first; int v = pi.second;
            if (dist[v] != di) continue;
            int rx = min(N, v+J);
            rep3r(t, v+1, rx+1) {
                ll ndi = di + T[t];
                if (dist[t] <= ndi) break;
                dist[t] = min(dist[t], ndi);
                que.emplace(ndi, t);
            }
        }
        return dist[N];
    }
};

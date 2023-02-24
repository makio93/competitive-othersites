// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

class FroggerAndNets {
public:
    int jump(string stones, int C, int minW, int seed) {
        int state = seed, N = stones.length(), maxW = N-1;
        vector<int> lids(N), rids(N);
        int pid = -1;
        rep(i, N) {
            if (stones[i] == 'O') pid = i;
            rids[i] = pid;
        }
        pid = -1;
        repr(i, N) {
            if (stones[i] == 'O') pid = i;
            lids[i] = pid;
        }
        vector<ll> dp(2), ndp;
        int pli = -1, pri = -1;
        rep(i, C) {
            state = (int)((state * 1103515245LL + 12345) % (1LL<<31));
            int w = minW + (state % (maxW - minW + 1));
            state = (int)((state * 1103515245LL + 12345) % (1LL<<31));
            int Li = state % (N - w), Ri = Li + w;
            ndp.assign(2, 0LL);
            if (rids[Ri] < Li) return -1;
            int vli = lids[Li], vri = rids[Ri];
            if (i == 0) ndp = dp;
            else {
                const vector<int> pids = { pli, pri }, vids = { vli, vri };
                rep(j1, 2) rep(j2, 2) ndp[j2] = max(ndp[j2], dp[j1]+abs(pids[j1]-vids[j2]));
            }
            swap(ndp, dp);
            pli = vli;
            pri = vri;
        }
        return (int)max(dp[0], dp[1]);
    }
};

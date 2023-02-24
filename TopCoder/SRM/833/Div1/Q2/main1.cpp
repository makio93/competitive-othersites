// 解説AC

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
            int w = (int)(minW + (state % (maxW - minW + 1)));
            state = (state * 1103515245 + 12345) % mod;
            L[i] = (int)(state % (N - w));
            R[i] = (int)(L[i] + w);
        }
        vector<int> lids(N), rids(N);
        int pid = -1;
        rep(i, N) {
            if (stones[i] == 'O') pid = i;
            lids[i] = pid;
        }
        pid = N;
        repr(i, N) {
            if (stones[i] == 'O') pid = i;
            rids[i] = pid;
        }
        vector<int> lstones(C), rstones(C);
        rep(i, C) {
            if (rids[L[i]] > R[i]) return -1;
            lstones[i] = rids[L[i]];
            rstones[i] = lids[R[i]];
        }
        vector<vector<int>> dp(C, vector<int>(2));
        rep3(i, 1, C) {
            dp[i][0] = max(dp[i-1][0]+abs(lstones[i]-lstones[i-1]), dp[i-1][1]+abs(lstones[i]-rstones[i-1]));
            dp[i][1] = max(dp[i-1][0]+abs(rstones[i]-lstones[i-1]), dp[i-1][1]+abs(rstones[i]-rstones[i-1]));
        }
        return max(dp[C-1][0], dp[C-1][1]);
    }
};

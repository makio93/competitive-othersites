// 学習1回目,解説AC

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
        vector<int> L(C), R(C);
        rep(i, C) {
            state = (int)((state * 1103515245LL + 12345) % (1LL<<31));
            int w = minW + (state % (maxW - minW + 1));
            state = (int)((state * 1103515245LL + 12345) % (1LL<<31));
            L[i] = state % (N - w);
            R[i] = L[i] + w;
        }
        vector<int> nextStone(N), prevStone(N);
        int pid = -1;
        repr(i, N) {
            if (stones[i] == 'O') pid = i;
            nextStone[i] = pid;
        }
        pid = -1;
        rep(i, N) {
            if (stones[i] == 'O') pid = i;
            prevStone[i] = pid;
        }
        vector<vector<int>> targetStone(C, vector<int>(2));
        rep(i, C) targetStone[i] = { nextStone[L[i]], prevStone[R[i]] };
        vector<vector<ll>> dp(C, vector<ll>(2));
        rep(i, C) {
            if (targetStone[i][1] < L[i]) return -1;
            if (i > 0) rep(j1, 2) rep(j2, 2) dp[i][j2] = max(dp[i][j2], dp[i-1][j1]+abs(targetStone[i][j2]-targetStone[i-1][j1]));
        }
        return (int)max(dp[C-1][0], dp[C-1][1]);
    }
};

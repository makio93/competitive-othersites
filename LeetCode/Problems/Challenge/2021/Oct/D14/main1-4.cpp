#include <bits/stdc++.h>
using namespace std;

// 解説AC4,BFS解法

class Solution {
    int INF = (int)(1e9);
public:
    int numSquares(int n) {
        if (n <= 0) return 0;
        vector<int> vals;
        for (int i=1; i*i<=n; ++i) vals.push_back(i*i);
        vector<int> dp(n+1, INF);
        queue<int> que;
        dp[0] = 0;
        que.push(0);
        while (!que.empty() || dp[n]==INF) {
            int v = que.front(); que.pop();
            int d = dp[v], nd = d + 1;
            for (int vi : vals) {
                int nv = v + vi;
                if (nv > n) break;
                if (dp[nv] <= nd) continue;
                dp[nv] = nd;
                if (nv == n) break;
                que.push(nv);
            }
        }
        return dp[n];
    }
};

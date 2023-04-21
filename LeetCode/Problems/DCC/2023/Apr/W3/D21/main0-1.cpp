// 自力AC1

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
const ll mod = (ll)(1e9) + 7;
class Solution {
public:
    int profitableSchemes(int n, int minProfit, vector<int>& group, vector<int>& profit) {
        int m = group.size();
        vector<vector<ll>> dp(n+1, vector<ll>(minProfit+1)), ndp;
        dp[0][0] = 1;
        for (int i1=0; i1<m; ++i1) {
            ndp = dp;
            for (int i=0; i<=n; ++i) for (int j=0; j<=minProfit; ++j) {
                if (i+group[i1] > n) continue;
                ndp[i+group[i1]][min(minProfit,j+profit[i1])] = (ndp[i+group[i1]][min(minProfit,j+profit[i1])] + dp[i][j]) % mod;
            }
            swap(ndp, dp);
        }
        ll res = 0;
        for (int i=0; i<=n; ++i) res = (res + dp[i][minProfit]) % mod;
        return (int)res;
    }
};

#include <bits/stdc++.h>
using namespace std;

// 本番AC

using ll = long long;
class Solution {
    const ll mod = (ll)(1e9) + 7;
public:
    int colorTheGrid(int m, int n) {
        int pat = 1;
        for (int i=0; i<m; ++i) pat *= 3;
        vector<int> from;
        for (int i=0; i<pat; ++i) {
            vector<int> col;
            int tmp = i;
            for (int j=0; j<m; ++j) {
                col.push_back(tmp%3);
                tmp /= 3;
            }
            bool ok = true;
            for (int j=0; j<m-1; ++j) if (col[j] == col[j+1]) ok = false;
            if (ok) from.push_back(i);
        }
        int flen = from.size();
        vector<vector<int>> to(flen);
        for (int i=0; i<flen; ++i) {
            vector<int> col;
            int tmp = from[i];
            for (int j=0; j<m; ++j) {
                col.push_back(tmp%3);
                tmp /= 3;
            }
            for (int j=0; j<flen; ++j) {
                vector<int> col2;
                int tmp2 = from[j];
                for (int j2=0; j2<m; ++j2) {
                    col2.push_back(tmp2%3);
                    tmp2 /= 3;
                }
                bool ok = true;
                for (int j2=0; j2<m; ++j2) if (col[j2] == col2[j2]) ok = false;
                if (ok) to[i].push_back(j);
            }
        }
        vector<vector<ll>> dp(n, vector<ll>(flen));
        dp[0] = vector<ll>(flen, 1);
        for (int i=0; i<n-1; ++i) for (int j=0; j<flen; ++j) {
            for (int t : to[j]) dp[i+1][t] = (dp[i+1][t] + dp[i][j]) % mod;
        }
        ll res = 0;
        for (int i=0; i<flen; ++i) res = (res + dp[n-1][i]) % mod;
        return (int)res;
    }
};

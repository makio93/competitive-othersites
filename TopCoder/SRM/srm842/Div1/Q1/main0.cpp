// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

class StringReduction {
public:
    int reduce(string start, vector<int> X, string Y) {
        int n = start.length(), m = X.size();
        vector<int> ccnt(26);
        rep(i, n) ccnt[start[i]-'a']++;
        vector<vector<int>> vals(26);
        rep(i, m) vals[Y[i]-'a'].push_back(X[i]-1);
        vector<vector<bool>> dp(26);
        rep(i, 26) dp[i].assign(ccnt[i], false);
        int res = 0;
        rep(i, 26) {
            int len = dp[i].size();
            if (len == 0) continue;
            dp[i][0] = true;
            for (const auto& val : vals[i]) rep(j, len) if (j-val>=0 && dp[i][j-val]) dp[i][j] = true;
            int mval = -1;
            rep(j, len) if (dp[i][j]) mval = j;
            res += len - mval;
        }
        return res;
    }
};

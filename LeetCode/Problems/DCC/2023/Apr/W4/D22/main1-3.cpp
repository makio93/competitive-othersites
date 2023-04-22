// 解説AC3(DP,メモリ削減)

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minInsertions(string s) {
        int n = s.length();
        string rs(s.rbegin(), s.rend());
        vector<int> dp(n+1), ndp(n+1);
        int mval = 0;
        for (int i=0; i<=n; ++i) {
            for (int j=0; j<=n; ++j) {
                if (i==0 || j==0) ndp[j] = 0;
                else if (s[i-1] == rs[j-1]) ndp[j] = dp[j-1] + 1;
                else ndp[j] = max(ndp[j-1], dp[j]);
            }
            mval = max(mval, ndp[n]);
            swap(ndp, dp);
        }
        return n - mval;
    }
};

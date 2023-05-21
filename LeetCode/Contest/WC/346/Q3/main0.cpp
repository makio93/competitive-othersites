// 本番AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
    bool is_punish(int val) {
        string nstr = to_string(val*val);
        int nlen = nstr.length();
        vector<vector<bool>> dp(nlen+1, vector<bool>(val+1));
        dp[0][0] = true;
        for (int i=0; i<nlen; ++i) for (int j=0; j<=val; ++j) if (dp[i][j]) {
            for (int k=i+1; k<=nlen; ++k) {
                int tval = j + stoi(nstr.substr(i, k-i));
                if (tval <= val) dp[k][tval] = true;
            }
        }
        return dp[nlen][val];
    }
public:
    int punishmentNumber(int n) {
        int res = 0;
        for (int i=1; i<=n; ++i) if (is_punish(i)) res += i * i;
        return res;
    }
};

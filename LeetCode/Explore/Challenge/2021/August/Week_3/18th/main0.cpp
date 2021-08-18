#include <bits/stdc++.h>
using namespace std;

// 自力AC-1

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            int sval1 = stoi(s.substr(i-1, 1));
            if (sval1>=1 && sval1<=9) dp[i] += dp[i-1];
            if (i-2 >= 0) {
                int sval2 = stoi(s.substr(i-2, 2));
                if (s[i-2]!='0' && sval2>=10 && sval2<=26) dp[i] += dp[i-2];
            }
        }
        return dp[n];
    }
};

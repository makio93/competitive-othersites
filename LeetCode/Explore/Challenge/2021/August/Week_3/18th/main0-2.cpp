#include <bits/stdc++.h>
using namespace std;

// 自力AC-2,Space:O(1)

class Solution {
public:
    int numDecodings(string s) {
        int n = s.length();
        vector<int> dp(3);
        dp[0] = 1;
        for (int i=1; i<=n; ++i) {
            dp[i%3] = 0;
            int sval1 = stoi(s.substr(i-1, 1));
            if (sval1>=1 && sval1<=9) dp[i%3] += dp[(i-1)%3];
            if (i-2 >= 0) {
                int sval2 = stoi(s.substr(i-2, 2));
                if (s[i-2]!='0' && sval2>=10 && sval2<=26) dp[i%3] += dp[(i-2)%3];
            }
        }
        return dp[n%3];
    }
};

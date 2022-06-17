// 解説AC1-1,メモリ削減

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length(), rlen = 0;
        string rs(s.rbegin(), s.rend());
        pair<int, int> mids = { -1, -1 };
        vector<vector<int>> dp(2, vector<int>(n+1));
        for (int i=0; i<n; ++i) for (int j=0; j<n; ++j) {
            if (s[i] == rs[j]) {
                dp[(i+1)%2][j+1] = dp[i%2][j] + 1;
                if (i+j-n+2==dp[(i+1)%2][j+1] && dp[(i+1)%2][j+1]>rlen) {
                    rlen = dp[(i+1)%2][j+1];
                    mids = { i, j };
                }
            }
            else dp[(i+1)%2][j+1] = 0;
        }
        return s.substr(mids.first-rlen+1, rlen);
    }
};

// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestValidParentheses(string s) {
        int n = s.length();
        vector<int> dp(n+1);
        int res = 0;
        for (int i=1; i<n; ++i) if (s[i] == ')') {
            if (s[i-1] == '(') dp[i+1] = dp[i-1] + 2;
            else if (i-dp[i]-1>=0 && s[i-dp[i]-1]=='(') dp[i+1] = dp[i] + dp[i-dp[i]-1] + 2;
            res = max(res, dp[i+1]);
        }
        return res;
    }
};

// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int countVowelStrings(int n) {
        vector<int> dp(6);
        for (int i=1; i<=5; ++i) dp[i] = 1;
        for (int i=0; i<n; ++i) for (int j=1; j<=5; ++j) dp[j] += dp[j-1];
        return dp[5];
    }
};

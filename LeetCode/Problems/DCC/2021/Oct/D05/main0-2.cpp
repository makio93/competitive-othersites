#include <bits/stdc++.h>
using namespace std;

// 自力AC2,Space:O(1)解

class Solution {
public:
    int climbStairs(int n) {
        int dp[3] = { 1, 0, 0 };
        for (int i=0; i<n; ++i) {
            dp[(i+1)%3] += dp[i%3];
            dp[(i+2)%3] = dp[i%3];
        }
        return dp[n%3];
    }
};

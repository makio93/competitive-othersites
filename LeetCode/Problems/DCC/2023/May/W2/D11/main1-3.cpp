// 解説AC3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<int> dp(m+1), ndp;
        for (int i=0; i<n; ++i) {
            ndp.assign(m+1, 0);
            for (int j=0; j<m; ++j) {
                if (nums1[i] == nums2[j]) ndp[j+1] = dp[j] + 1;
                else ndp[j+1] = max(dp[j+1], ndp[j]);
            }
            dp = move(ndp);
        }
        return dp[m];
    }
};

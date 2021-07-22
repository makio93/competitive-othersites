#include <bits/stdc++.h>
using namespace std;

// 自力解答1,AC

class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>> dp(n+1, vector<int>(m+1));
        int res = 0;
        for (int i=0; i<n; ++i) for (int j=0; j<m; ++j) {
            if (nums1[i] == nums2[j]) dp[i+1][j+1] = dp[i][j] + 1;
            res = max(res, dp[i+1][j+1]);
        }
        return res;
    }
};

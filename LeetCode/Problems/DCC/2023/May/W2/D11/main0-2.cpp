// 自力AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        if (n < m) {
            swap(n, m);
            swap(nums1, nums2);
        }
        vector<int> dp(m, m);
        for (int i=0; i<n; ++i) for (int j=m-1; j>=0; --j) if (nums1[i] == nums2[j]) *lower_bound(dp.begin(), dp.end(), j) = j;
        int res = 0;
        for (int i=0; i<m; ++i) if (dp[i] < m) res = i + 1;
        return res;
    }
};

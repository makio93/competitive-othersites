// 本番WA

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minChanges(vector<int>& nums, int k) {
        int n = nums.size(), ans = n;
        vector<vector<int>> tnums = { nums, nums };
        for (int i=0; i<k; ++i) tnums[0][k-1] ^= nums[i];
        for (int i=k; i<n; ++i) tnums[0][i] = tnums[0][i-k];
        for (int i=n-1; i>=n-k; --i) tnums[1][n-k] ^= nums[i];
        for (int i=n-k-1; i>=0; --i) tnums[1][i] = tnums[1][i+k];
        for (int i=0; i<2; ++i) {
            int cnt = 0;
            for (int j=0; j<n; ++j) if (nums[j] != tnums[i][j]) ++cnt;
            ans = min(ans, cnt);
        }
        return ans;
    }
};

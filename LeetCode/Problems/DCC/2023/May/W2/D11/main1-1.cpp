// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
    vector<int> nums1, nums2;
    vector<vector<int>> memo;
    int dfs(int i1, int i2) {
        if (memo[i1][i2] != -1) return memo[i1][i2];
        if (i1==0 || i2==0) return memo[i1][i2] = 0;
        if (nums1[i1-1] == nums2[i2-1]) return memo[i1][i2] = 1 + dfs(i1-1, i2-1);
        return memo[i1][i2] = max(dfs(i1-1, i2), dfs(i1, i2-1));
    }
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        this->nums1 = move(nums1), this->nums2 = move(nums2);
        memo.assign(n+1, vector<int>(m+1, -1));
        return dfs(n, m);
    }
};

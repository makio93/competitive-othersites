// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int longestSubsequence(vector<int>& arr, int difference) {
        int n = arr.size(), res = 0;
        unordered_map<int, int> dp;
        for (int i=0; i<n; ++i) {
            if (dp.find(arr[i]-difference) == dp.end()) dp[arr[i]] = 1;
            else dp[arr[i]] = max(dp[arr[i]], dp[arr[i]-difference]+1);
            res = max(res, dp[arr[i]]);
        }
        return res;
    }
};

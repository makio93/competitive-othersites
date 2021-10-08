#include <bits/stdc++.h>
using namespace std;

// 解説AC2,O(nlogn)解法(?)

const int INF = (int)(1e9);
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<vector<int>> cid(26);
        for (int i=0; i<m; ++i) cid[text2[i]-'a'].push_back(i);
        vector<int> sid;
        for (int i=0; i<n; ++i) sid.insert(sid.end(), cid[text1[i]-'a'].rbegin(), cid[text1[i]-'a'].rend());
        int len = sid.size();
        vector<int> dp(len+1, INF);
        for (int i=0; i<len; ++i) *lower_bound(dp.begin(), dp.end(), sid[i]) = sid[i];
        int res = 0;
        for (int i=0; i<len+1; ++i) if (dp[i] != INF) res = max(res, i+1);
        return res;
    }
};

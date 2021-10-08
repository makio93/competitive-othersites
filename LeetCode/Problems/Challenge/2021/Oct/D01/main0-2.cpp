#include <bits/stdc++.h>
using namespace std;

// 自力WA,O(nlogn)解法

const int INF = (int)(1e9);
class Solution {
public:
    int longestCommonSubsequence(string text1, string text2) {
        int n = text1.length(), m = text2.length();
        vector<set<int>> cid(26);
        for (int i=0; i<m; ++i) cid[text2[i]-'a'].insert(i);
        vector<int> dp(m+1, INF);
        dp[0] = -1;
        for (int i=0; i<n; ++i) if (!cid[text1[i]-'a'].empty()) {
            int di = *prev(lower_bound(dp.begin(), dp.end(), INF));
            auto itr = cid[text1[i]-'a'].upper_bound(di);
            if (itr == cid[text1[i]-'a'].end()) --itr;
            while (!cid[text1[i]-'a'].empty()) {
                auto pitr = lower_bound(dp.begin(), dp.end(), *itr);
                *pitr = min(*pitr, *itr);
                if (itr == cid[text1[i]-'a'].begin()) {
                    cid[text1[i]-'a'].erase(itr);
                    break;
                }
                else itr = prev(cid[text1[i]-'a'].erase(itr));
            }
        }
        int res = 0;
        for (int i=0; i<m+1; ++i) if (dp[i] != INF) res = max(res, i);
        return res;
    }
};

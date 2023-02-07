// 自力AC

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& left, vector<int>& right) -> bool {
            return (left[0] != right[0]) ? (left[0] < right[0]) : (left[1] > right[1]);
        });
        vector<int> dp(n+1, INF);
        for (int i=0; i<n; ++i) *lower_bound(dp.begin(), dp.end(), envelopes[i][1]) = envelopes[i][1];
        int res = n+1;
        for (int i=0; i<n+1; ++i) if (dp[i] == INF) {
            res = i;
            break;
        }
        return res;
    }
};

// 解説AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int maxEnvelopes(vector<vector<int>>& envelopes) {
        int n = envelopes.size();
        sort(envelopes.begin(), envelopes.end(), [&](vector<int>& left, vector<int>& right) -> bool {
            return (left[0] != right[0]) ? (left[0] < right[0]) : (left[1] > right[1]); });
        vector<int> dp;
        for (int i=0; i<n; ++i) {
            int id = lower_bound(dp.begin(), dp.end(), envelopes[i][1]) - dp.begin();
            if (id == (int)(dp.size())) dp.push_back(envelopes[i][1]);
            else dp[id] = envelopes[i][1];
        }
        return (int)dp.size();
    }
};

// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;
class Solution {
public:
    int longestSquareStreak(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        vector<int> dp(n, 1);
        unordered_map<ll, vector<int>> ids;
        for (int i=0; i<n; ++i) ids[(ll)nums[i]].push_back(i);
        for (int i=0; i<n-1; ++i) {
            ll sval = (ll)nums[i] * nums[i];
            if (ids.find(sval) != ids.end()) {
                auto itr = upper_bound(ids[sval].begin(), ids[sval].end(), i);
                if (itr != ids[sval].end()) dp[*itr] = max(dp[*itr], dp[i]+1);
            }
        }
        int res = *max_element(dp.begin(), dp.end());
        if (res <= 1) return -1;
        else return res;
    }
};

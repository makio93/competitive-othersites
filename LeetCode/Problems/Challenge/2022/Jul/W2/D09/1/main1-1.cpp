// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1e9);
class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> dp(n, -INF);
        multiset<int, greater<int>> st;
        dp[0] = nums[0];
        st.insert(dp[0]);
        for (int i=1; i<n; ++i) {
            if (i-k-1 >= 0) st.erase(st.find(dp[i-k-1]));
            dp[i] = *st.begin() + nums[i];
            st.insert(dp[i]);
        }
        return dp[n-1];
    }
};

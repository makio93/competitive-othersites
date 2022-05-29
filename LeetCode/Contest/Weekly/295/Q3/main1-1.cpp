// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int totalSteps(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n);
        int res = 0;
        stack<int> st;
        st.push(n-1);
        for (int i=n-2; i>=0; --i) {
            while (!st.empty() && nums[i]>nums[st.top()]) {
                dp[i] = max(dp[i]+1, dp[st.top()]);
                st.pop();
            }
            st.push(i);
            res = max(res, dp[i]);
        }
        return res;
    }
};

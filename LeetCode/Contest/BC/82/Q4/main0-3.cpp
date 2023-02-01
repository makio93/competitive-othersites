// 本番WA3

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        stack<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && nums[st.top()]>=nums[i]) st.pop();
            int len = (st.empty()) ? i+1 : i-st.top();
            st.push(i);
            if (nums[i] > threshold/len) return len;
        }
        int mval = (int)(1.5e9);
        while (!st.empty()) {
            mval = min(mval, nums[st.top()]);
            st.pop();
        }
        if (mval > threshold/n) return n;
        return -1;
    }
};

// 解説AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        stack<int> st;
        for (int i=n-1; i>=1; --i) {
            if (nums[i] <= mvals[i-1]) continue;
            while (!st.empty() && st.top()<=mvals[i-1]) st.pop();
            if (!st.empty() && st.top()<nums[i]) return true;
            st.push(nums[i]);
        }
        return false;
    }
};

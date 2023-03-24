// 学習1回目,解説AC2

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        int n = nums.size(), li = n, ri = 0;
        stack<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && nums[st.top()]>nums[i]) li = min(li, st.top()), st.pop();
            st.push(i);
        }
        while (!st.empty()) st.pop();
        for (int i=n-1; i>=0; --i) {
            while (!st.empty() && nums[st.top()]<nums[i]) ri = max(ri, st.top()), st.pop();
            st.push(i);
        }
        return max(0, ri-li+1);
    }
};

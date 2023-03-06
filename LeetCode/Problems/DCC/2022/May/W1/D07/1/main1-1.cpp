// 学習1回目,解説AC1

#include <bits/stdc++.h>
using namespace std;

const int INF = (int)(1.5e9);
class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        stack<int> st;
        st.push(INF);
        for (int i=n-1; i>=1; --i) {
            if (nums[i] <= mvals[i]) continue;
            while (st.top() <= mvals[i]) st.pop();
            if (st.top() < nums[i]) return true;
            if (nums[i] < st.top()) st.push(nums[i]);
        }
        return false;
    }
};

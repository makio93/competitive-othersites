// 学習1回目,自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int n = nums.size();
        vector<int> mvals(n);
        mvals[0] = nums[0];
        for (int i=1; i<n; ++i) mvals[i] = min(mvals[i-1], nums[i]);
        set<int> st;
        for (int i=n-2; i>=1; --i) {
            st.insert(nums[i+1]);
            auto itr = st.lower_bound(nums[i]);
            if (itr!=st.begin() && *prev(itr)>mvals[i]) return true;
        }
        return false;
    }
};

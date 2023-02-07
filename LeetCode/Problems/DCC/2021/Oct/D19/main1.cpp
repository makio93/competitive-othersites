#include <bits/stdc++.h>
using namespace std;

// 解説AC,Time&Space:O(N+M)解法

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        stack<int> st;
        unordered_map<int, int> nvals;
        for (int val : nums2) {
            while (!st.empty() && st.top()<val) {
                nvals[st.top()] = val;
                st.pop();
            }
            st.push(val);
        }
        while (!st.empty()) {
            nvals[st.top()] = -1;
            st.pop();
        }
        vector<int> ans;
        for (int val : nums1) ans.push_back(nvals[val]);
        return ans;
    }
};

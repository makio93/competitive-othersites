#include <bits/stdc++.h>
using namespace std;

// 解説AC1

class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        heights.push_back(0);
        int n = heights.size(), res = 0;
        stack<int> st;
        for (int i=0; i<n; ++i) {
            while (!st.empty() && heights[st.top()]>=heights[i]) {
                int hval = heights[st.top()];
                st.pop();
                int lid = (!st.empty() ? st.top() : -1);
                res = max(res, hval*(i-lid-1));
            }
            st.push(i);
        }
        return res;
    }
};

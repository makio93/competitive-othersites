// 自力AC

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    vector<int> canSeePersonsCount(vector<int>& heights) {
        int n = heights.size();
        stack<int> st;
        vector<int> res(n);
        for (int i=n-1; i>=0; --i) {
            while (!st.empty() && heights[st.top()]<heights[i]) {
                res[i]++;
                st.pop();
            }
            if (!st.empty()) res[i]++;
            st.push(i);
        }
        return res;
    }
};

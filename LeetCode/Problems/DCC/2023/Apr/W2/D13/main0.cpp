// 自力AC1

#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int n = pushed.size();
        stack<int> st;
        for (int i=0,j=0; i<n; ++i) {
            st.push(pushed[i]);
            while (j<n && !st.empty() && st.top()==popped[j]) {
                st.pop();
                ++j;
            }
        }
        return st.empty();
    }
};

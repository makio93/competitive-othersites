#include <bits/stdc++.h>
using namespace std;

// 解説AC2,O(N^2)

const int INF = (int)(1e9);

class Solution {
public:
    int maximalRectangle(vector<vector<char>>& matrix) {
        if (matrix.empty()) return 0;
        int n = matrix.size(), m = matrix.front().size();
        if (m == 0) return 0;
        int res = 0;
        vector<int> dp(m);
        for (int i=0; i<n; ++i) {
            for (int j=0; j<m; ++j) {
                if (matrix[i][j] == '1') dp[j]++;
                else dp[j] = 0;
            }
            stack<int> st;
            st.push(-1);
            for (int j=0; j<=m; ++j) {
                int val = (j == m) ? -1 : dp[j];
                while (st.top()!=-1 && dp[st.top()]>val) {
                    int hval = dp[st.top()];
                    st.pop();
                    res = max(res, hval*((j-1)-st.top()));
                }
                st.push(j);
            }
        }
        return res;
    }
};

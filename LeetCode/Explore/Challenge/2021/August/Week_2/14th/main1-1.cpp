#include <bits/stdc++.h>
using namespace std;

// 解説AC,1

class Solution {
    vector<vector<vector<int>>> dp;
    int calc(vector<int>& boxes, int i, int j, int k) {
        if (dp[i][j][k] != -1) return dp[i][j][k];
        if (i >= j) return (dp[i][j][k] = 0);
        int res = (k+1) * (k+1) + calc(boxes, i+1, j, 0);
        for (int m=i+1; m<j; ++m) if (boxes[i] == boxes[m]) {
            res = max(res, calc(boxes,i+1,m,0)+calc(boxes,m,j,k+1));
        }
        return (dp[i][j][k] = res);
    }
public:
    int removeBoxes(vector<int>& boxes) {
        int n = boxes.size();
        dp = vector<vector<vector<int>>>(n+1, vector<vector<int>>(n+1, vector<int>(n, -1)));
        return calc(boxes, 0, n, 0);
    }
};

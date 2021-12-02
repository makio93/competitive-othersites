#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n+1);
        for (int i=1; i<=n; ++i) for (int j=0; j<i; ++j) {
            dp[i].push_back((int)(1e9));
            if (j-1 >= 0) dp[i][j] = min(dp[i][j], dp[i-1][j-1]+triangle[i-1][j]);
            if (j < i-1) dp[i][j] = min(dp[i][j], dp[i-1][j]+triangle[i-1][j]);
            if (dp[i][j] == (int)(1e9)) dp[i][j] = triangle[i-1][j];
        }
        int res = (int)(1e9);
        for (int i=0; i<n; ++i) res = min(res, dp[n][i]);
        return res;
    }
};

int main(){
    Solution cl;
    int n;
    cin >> n;
    vector<vector<int>> triangle(n);
    for (int i=0; i<n; ++i) for (int j=0; j<=i; ++j) {
        int val;
        cin >> val;
        triangle[i].push_back(val);
    }
    cout << cl.minimumTotal(triangle) << endl;
    return 0;
}

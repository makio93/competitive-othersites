#include <iostream>
#include <vector>
#include <string>
using namespace std;

const int INF = (int)(1e9);

int main()
{
    string s, t;
    cin >> s >> t;
    int n = s.length(), m = t.length();
    vector<vector<int>> dp(n+1, vector<int>(m+1));
    for (int i=0; i<n+1; ++i) dp[i][0] = INF;
    for (int i=1; i<=n; ++i) {
        dp[i] = dp[i-1];
        int cid = -1;
        for (int j=0; j<m; ++j) if (s[i-1] == t[j]) cid = j + 1;
        if (cid != -1) dp[i][cid] = max(dp[i][cid], min(dp[i-1][cid]+1, dp[i-1][cid-1]));
    }
    cout << (n - dp[n][m]*m) << endl;
    return 0;
}

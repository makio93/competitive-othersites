// 誤答

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, m;
    cin >> n >> m;
    vector<vector<long long>> dp(n+1, vector<long long>(n+1));
    dp[0][0] = 1;
    for (int i=1; i<=n; ++i) for (int j=1; j<=n; ++j) if (j%m != 0) {
        for (int j2=j; j2>=1; --j2) if (j2%m != 0) dp[i][j] += dp[i-1][j-j2];
    }
    long long res = 0;
    for (int i=1; i<=n; ++i) res += dp[i][n];
    cout << res << endl;
    return 0;
}

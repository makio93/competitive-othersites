#include <iostream>
#include <vector>
#include <string>
using namespace std;

// 本番WA

const long long mod = (long long)(1e9) + 7;

int main()
{
    string s;
    cin >> s;
    int n = s.length();
    vector<long long> dp(n+1), asum(n+1), bsum(n+1);
    dp[0] = dp[1] = 1;
    asum[0] = bsum[0] = 1;
    asum[1] = bsum[1] = 1;
    for (int i=2; i<=n; ++i) {
        dp[i] = (dp[i] + dp[i-1]) % mod;
        asum[i] = (asum[i] + asum[i-1]) % mod;
        bsum[i] = (bsum[i] + bsum[i-1]) % mod;
        if (s.substr(i-2, 2) == string("aa")) {
            dp[i] = (dp[i] + dp[i-2] - asum[i-2] + mod) % mod;
            asum[i] = (asum[i] + dp[i]) % mod;
        }
        else if (s.substr(i-2, 2) == string("bb")) {
            dp[i] = (dp[i] + dp[i-2] - bsum[i-2] + mod) % mod;
            bsum[i] = (bsum[i] + dp[i]) % mod;
        }
    }
    cout << dp[n] << endl;
    return 0;
}

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 

const ll mod = 998244353;

int main() {
    int n, m;
    cin >> n >> m;
    vector<string> b(n);
    rep(i, n) cin >> b[i];
    vector<vector<vector<ll>>> dp(n+1, vector<vector<ll>>(m+1, vector<ll>(5)));
    vector<vector<vector<ll>>> mul(n+1, vector<vector<ll>>(m+1, vector<ll>(5)));
    rep(i, m+1) mul[0][i][0] = 1;
    rep(i, n) rep(j, m) {
        if (b[i][j] == 'o') {
            if (j+1<m && b[i][j+1]=='o') {
                for (int li : { 0, 2, 3, 4 }) mul[i+1][j+1][1] = (mul[i+1][j+1][1] + mul[i+1][j][li]) % mod;
                for (int ui : { 0, 1, 2, 4 }) mul[i+1][j+1][1] = (mul[i+1][j+1][1] + mul[i][j+1][ui]) % mod;
                for (int li : { 0, 2, 3, 4 }) dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i+1][j][li]) % mod;
                for (int ui : { 0, 1, 2, 4 }) dp[i+1][j+1][1] = (dp[i+1][j+1][1] + dp[i][j+1][ui]) % mod;
            }
            if (j-1>=0 && b[i][j-1]=='o') {
                for (int li : { 1 }) mul[i+1][j+1][2] = (mul[i+1][j+1][2] + mul[i+1][j][li]) % mod;
                for (int ui : { 0, 1, 2, 4 }) mul[i+1][j+1][2] = (mul[i+1][j+1][2] + mul[i][j+1][ui]) % mod;
                for (int li : { 1 }) dp[i+1][j+1][2] = (dp[i+1][j+1][2] + dp[i+1][j][li]) % mod;
                for (int ui : { 0, 1, 2, 4 }) dp[i+1][j+1][2] = (dp[i+1][j+1][2] + dp[i][j+1][ui]) % mod;
                dp[i+1][j+1][2] = (dp[i+1][j+1][2] + mul[i+1][j+1][2]) % mod;
            }
            if (i+1<n && b[i+1][j]=='o') {
                for (int li : { 0, 2, 3, 4 }) mul[i+1][j+1][3] = (mul[i+1][j+1][3] + mul[i+1][j][li]) % mod;
                for (int ui : { 0, 1, 2, 4 }) mul[i+1][j+1][3] = (mul[i+1][j+1][3] + mul[i][j+1][ui]) % mod;
                for (int li : { 0, 2, 3, 4 }) dp[i+1][j+1][3] = (dp[i+1][j+1][3] + dp[i+1][j][li]) % mod;
                for (int ui : { 0, 1, 2, 4 }) dp[i+1][j+1][3] = (dp[i+1][j+1][3] + dp[i][j+1][ui]) % mod;
            }
            if (i-1>=0 && b[i-1][j]=='o') {
                
            }
        }
    }
    return 0;
}

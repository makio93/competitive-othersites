#include <iostream>
#include <vector>
using namespace std;

const long long mod = (long long)(1e9) + 7;
long long modint(long long a, long long b) {
    long long p = 1, q = a % mod;
    while (b > 0) {
        if (b&1) p = p * q % mod;
        q = q * q % mod;
        b >>= 1;
    }
    return p;
}

vector<vector<int>> g;
vector<int> e;
vector<vector<vector<long long>>> dp;
long long dfs(int d, int b=0, int v=0) {
    if (b==1 || e[d-1]==v) {
        dp[d][v][1] = (dp[d][v][1] + dp[d-1][v][0]) % mod;
        long long mul = 1, sum = 0;
        int zero = 0; bool zone = false;
        for (int t : g[v]) if ((dp[d-1][t][0]+dp[d-1][t][1])%mod == 0) ++zero;
        if (zero == 1) zone = true;
        for (int t : g[v]) if (!zone || (zone&&(dp[d-1][t][0]+dp[d-1][t][1])%mod!=0)) mul = mul * (dp[d-1][t][0] + dp[d-1][t][1]) % mod;
        for (int t : g[v]) {
            if (zone) {
                if (dp[d-1][t][0]+dp[d-1][t][1] == 0) sum = (sum + dfs(d, 1, t) * mul) % mod;
                else sum = (sum + dfs(d, 1, t) * 0) % mod;
            }
            else sum = (sum + dfs(d, 1, t) * mul % mod * modint(dp[d-1][t][0]+dp[d-1][t][1], mod-2)) % mod;
        }
        dp[d][v][0] = (dp[d][v][0] + (dp[d-1][v][0] + dp[d-1][v][1]) * sum) % mod;
    }
    else {
        long long res = 1;
        for (int t : g[v]) res = res * dfs(d, 0, t) % mod;
        dp[d][v][0] = (dp[d][v][0] + (dp[d-1][v][0] + dp[d-1][v][1]) * res) % mod;
    }
    return (dp[d][v][1] + dp[d][v][0]) % mod;
}

int main() {
    int n, m;
    cin >> n >> m;
    g = vector<vector<int>>(n);
    for (int i=1; i<n; ++i) {
        int pi;
        cin >> pi;
        --pi;
        g[pi].push_back(i);
    }
    vector<int> task(n);
    e = vector<int>(m);
    for (int i=0; i<m; ++i) {
        cin >> e[i];
        e[i]--;
        task[e[i]]++;
    }
    dp = vector<vector<vector<long long>>>(m+1, vector<vector<long long>>(n, vector<long long>(2)));
    for (int i=0; i<n; ++i) dp[0][i][0] = 1;
    for (int i=1; i<=m; ++i) dfs(i);
    cout << ((dp[m][0][0]+dp[m][0][1])%mod) << endl;
    return 0;
}

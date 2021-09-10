#include <iostream>
#include <vector>
using namespace std;

int mval, mod;
vector<vector<vector<long long>>> memo;
long long calc(int n, int m, int l) {
    if (memo[n][m][l] != -1LL) return memo[n][m][l];
    if (n==0 && l==0) return (memo[n][m][l] = 1);
    if (n%mod==m || n%mod==0) return (memo[n][m][l] = 0);
    if (l > n) return (memo[n][m][l] = 0);
    if ((l!=0) xor (n!=0)) return (memo[n][m][l] = 0);
    if (l == 1) return (memo[n][m][l] = 1);
    {
        long long res = 0;
        for (int i=1; n-i>=l-1; ++i) if (i%mod!=m && i%mod!=0) res += calc(n-i, (m-i%mod+mod)%mod, l-1);
        return (memo[n][m][l] = res);
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    mval = n; mod = m;
    memo = vector<vector<vector<long long>>>(n+1, vector<vector<long long>>(m, vector<long long>(n+1, -1)));
    long long res = 0;
    for (int i=n-2; i>=1; --i) {
        res += calc(n, 0, i);
        memo = vector<vector<vector<long long>>>(n+1, vector<vector<long long>>(m, vector<long long>(n+1, -1)));
    }
    cout << res << endl;
    return 0;
}

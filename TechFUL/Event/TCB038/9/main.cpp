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

int main() {
    int n, m;
    cin >> n >> m;
    vector<int> a(m);
    for (int i=0; i<m; ++i) cin >> a[i];
    long long res = 1;
    if (n-m-2 >= 0) res = modint(n-m, n-m-2) * modint(n-m, m) % mod;
    cout << res << endl;
    return 0;
}

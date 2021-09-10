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

vector<long long> fact, ifact;
long long choose(int n, int r) {
    if (r < 0) return 0;
    if (n-r < r) return choose(n, n-r);
    return fact[n] * ifact[n-r] % mod * ifact[r] % mod;
}

int main() {
    vector<int> a(10);
    for (int i=0; i<10; ++i) cin >> a[i];
    int sum = 0;
    for (int i=0; i<10; ++i) sum += a[i];
    fact = vector<long long>(sum+1); ifact = vector<long long>(sum+1);
    fact[0] = 1; ifact[0] = 1;
    for (int i=1; i<=sum; ++i) fact[i] = fact[i-1] * i % mod;
    for (int i=1; i<=sum; ++i) ifact[i] = ifact[i-1] * modint(i, mod-2) % mod;
    long long res = choose(sum-1, a[0]);
    sum -= a[0];
    for (int i=1; i<10; ++i) {
        res = res * choose(sum, a[i]) % mod;
        sum -= a[i];
    }
    cout << res << endl;
    return 0;
}

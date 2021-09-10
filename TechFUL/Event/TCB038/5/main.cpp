#include <iostream>
using namespace std;
using ll = long long;

const ll mod = (ll)(1e9) + 7;

ll modint(ll a, ll b) {
    ll p = 1, q = a % mod;
    while (b > 0) {
        if (b&1) p = p * q % mod;
        q = q * q % mod;
        b >>= 1;
    }
    return p;
}

int main() {
    int n, k;
    cin >> n >> k;
    cout << modint(2, max(0,n-k-1)) << endl;
    return 0;
}

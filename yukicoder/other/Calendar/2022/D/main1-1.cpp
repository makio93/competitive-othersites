// 解説AC1

#include <bits/stdc++.h>
#include <atcoder/all>
using namespace std;
using namespace atcoder;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
ll modpow(ll a, ll b) {
	ll p = 1, q = a;
	rep(i, 63) {
		if (b & (1LL<<i)) p = p * q % mod;
		q = q * q % mod;
	}
	return p;
}

int main() {
    int n;
    string s;
    cin >> n >> s;
    vector<vector<ll>> memo(n, vector<ll>(3, -1));
    auto calc = [&](auto calc, int vi, int ci) -> ll {
        if (memo[vi][ci] != -1) return memo[vi][ci];
        if (vi == 0) {
            if (ci == s[vi]-'A') return memo[vi][ci] = 0;
            else return memo[vi][ci] = 1;
        }
        else {
            if (ci == s[vi]-'A') return memo[vi][ci] = calc(calc, vi-1, ci);
            else {
                int ti = -1;
                rep(i, 3) if (i!=ci && i!=s[vi]-'A') {
                    ti = i;
                    break;
                }
                return memo[vi][ci] = (calc(calc, vi-1, ti) + 1 + modpow(2, vi) - 1 + mod) % mod;
            }
        }
    };
    cout << calc(calc, n-1, 0) << endl;
    return 0;
}

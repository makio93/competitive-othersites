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

const ll mod = 998244353LL;
ll modpow(ll a, ll b) {
	ll p = 1, q = a;
	rep(i, 63) {
		if (b & (1LL<<i)) p = p * q % mod;
		q = q * q % mod;
	}
	return p;
}

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> two(n+1), itwo(n+1), c(n), csum(n+1);
	two[0] = 1;
	rep(i, n) two[i+1] = two[i] * 2 % mod;
	itwo[n] = modpow(two[n], mod-2);
	repr(i, n) itwo[i] = itwo[i+1] * 2 % mod;
	rep(i, n) c[i] = two[i] * a[i] % mod;
	rep(i, n) csum[i+1] = (csum[i] + c[i]) % mod;
	vector<int> lids(n);
	int lid = 0;
	rep3(i, 1, n) {
		if (a[i] <= a[i-1]) lid = i;
		lids[i] = lid;
	}
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li; --ri;
		ll res = 0;
		if (lids[ri] >= li) res = ((csum[ri+1] - csum[lids[ri]+1] + mod) % mod * itwo[lids[ri]+1] + a[lids[ri]]) % mod;
		else res = ((csum[ri+1] - csum[li+1] + mod) % mod * itwo[li+1] + a[li]) % mod;
		cout << res << endl;
	}
	return 0;
}

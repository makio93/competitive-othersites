// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n;
	ll m;
	cin >> n >> m;
	set<int> primes;
	ll sub = m, mul = 1;
	vector<ll> mvals;
	mvals.push_back(sub%mod);
	rep3(i, 2, n+1) {
		int ti = i;
		for (int j=2; j*j<=ti; ++j) if (ti%j == 0) {
			if (primes.find(j) == primes.end()) {
				if (mul <= m) mul *= j;
				primes.insert(j);
			}
			while (ti%j == 0) ti /= j;
		}
		if (ti > 1) {
			if (primes.find(ti) == primes.end()) {
				if (mul <= m) mul *= ti;
				primes.insert(ti);
			}
		}
		sub = sub % mod * ((m / mul) % mod) % mod;
		mvals.push_back(sub);
	}
	ll res = 0, sum = 1;
	rep(i, n) {
		sum = sum * (m%mod) % mod;
		res = (res + (sum - mvals[i] + mod)) % mod;
	}
	cout << res << endl;
	return 0;
}

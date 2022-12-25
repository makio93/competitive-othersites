// 本番AC

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

int main() {
	int n, q;
	cin >> n >> q;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	vector<ll> two(n+1, 1);
	rep(i, n) two[i+1] = two[i] * 2 % mod;
	vector<ll> sums(n+1);
	vector<int> sids;
	sids.push_back(n);
	ll nval = 0;
	repr(i, n) {
		sums[i+1] = nval;
		if (i-1<0 || a[i-1]>=a[i]) {
			sids.push_back(i);
			nval = 0;
		}
		else nval = (nval * 2 + a[i]) % mod;
	}
	reverse(all(sids));
	rep(i, q) {
		int li, ri;
		cin >> li >> ri;
		--li;
		int ti = lower_bound(all(sids), ri) - sids.begin(), pi = ti - 1, spi = max(li+1, sids[pi]+1);
		ll res = (sums[spi] - sums[ri] * two[ri-spi] % mod + mod + a[spi-1]) % mod;
		cout << res << endl;
	}
	return 0;
}

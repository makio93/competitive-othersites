// 本番WA

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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n, x;
		cin >> n >> x;
		ll res = 0;
		if (x%2 == 1) res = (n+1) / 2 % mod;
		else {
			res += n / x * x / 2 % mod;
			if (n/x%2 == 0) {
				if (n/x >= 2) res = (res + ((n%x+1) + 1) / 2) % mod;
				else res = (res + (n%x+1) / 2) % mod;
			}
			else {
				if (n/x >= 2) res = (res + (n%x+1) / 2) % mod;
				else res = (res + ((n%x+1) + 1) / 2) % mod;
			}
		}
		cout << res << endl;
	}
	return 0;
}

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

int gcd(int a, int b) { return (b ? gcd(b, a%b) : a); }

int main() {
	int n;
	cin >> n;
	vector<int> a(n);
	rep(i, n) cin >> a[i];
	unordered_map<int, ll> dp;
	rep(i, n) {
		unordered_map<int, ll> ndp;
		ndp[a[i]] = (ndp[a[i]] + 1) % mod;
		for (auto& pi : dp) {
			int gval = gcd(pi.first, a[i]);
			if (gval > 1) ndp[gval] = (ndp[gval] + pi.second) % mod;
		}
		for (auto& pi : ndp) dp[pi.first] = (dp[pi.first] + pi.second) % mod;
	}
	ll res = 0;
	for (auto& pi : dp) res = (res + pi.second) % mod;
	cout << res << endl;
	return 0;
}

// 本番TLE

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = (ll)(1e9) + 7;
struct mint {
	ll x;
	mint(ll x=0) : x((x%mod+mod)%mod) {}
	mint operator-() const { return mint(-x); }
	mint& operator+=(const mint a) {
		if ((x += a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator-=(const mint a) {
		if ((x += mod-a.x) >= mod) x -= mod;
		return *this;
	}
	mint& operator*=(const mint a) { (x *= a.x) %= mod; return *this;}
	mint operator+(const mint a) const { return mint(*this) += a;}
	mint operator-(const mint a) const { return mint(*this) -= a;}
	mint operator*(const mint a) const { return mint(*this) *= a;}
	mint pow(ll t) const {
		if (!t) return 1;
		mint a = pow(t>>1);
		a *= a;
		if (t&1) a *= *this;
		return a;
	}
	mint inv() const { return pow(mod-2);}
	mint& operator/=(const mint a) { return *this *= a.inv();}
	mint operator/(const mint a) const { return mint(*this) /= a;}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, k;
	cin >> n >> k;
	mint res = 0;
	if (k >= n) {
		res = mint(2).pow(n);
		cout << res.x << endl;
		return 0;
	}
	vector<mint> dp(k+1);
	dp[0] = 1;
	rep3(i, 1, k+1) {
		dp[i] = mint(2).pow(i) + dp[i-1];
	}
	map<pair<int, int>, mint> memo;
	auto calc = [&](auto calc, int di, int ki) -> mint {
		if (memo.find({ di, ki }) != memo.end()) return memo[{ di, ki }];
		if (ki==0 || di-1==ki) return memo[{ di, ki }] = dp[ki];
		else return memo[{ di, ki }] = calc(calc, di-1, ki) + calc(calc, di-1, ki-1);
	};
	cout << calc(calc, n, k).x << endl;
	return 0;
}

// 本番WA

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const ll mod = 998244353LL;
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
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		string a, b;
		cin >> n >> a >> b;
		int bcnt = 0;
		rep(i, n) if (a[i] != b[i]) ++bcnt;
		if (bcnt == 0) {
			cout << 0 << endl;
			continue;
		}
		vector<mint> vals(n+1);
		vals[0] = 1;
		rep(i, n) vals[i+1] = vals[i] * mint(i+1) / n;
		vector<mint> dp(n+1);
		dp[n] = vals[n].inv();
		mint res = 0;
		rep3r(i, 1, n) {
			dp[i] = dp[i+1] * mint(n-i) / n + vals[i-1].inv() * mint(i) / n;
			if (i == bcnt) {
				res = dp[i];
				break;
			}
		}
		cout << res.x << endl;
	}
	return 0;
}

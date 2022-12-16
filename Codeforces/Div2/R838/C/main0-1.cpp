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
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	map<pair<int, int>, mint> memo;
	auto cb = [&](auto cb, int a, int b) -> mint {
		if (memo.find({a, b}) != memo.end()) return memo[{a, b}];
		if (a == b) return memo[{ a, b }] = mint(2).pow(a);
		if (b == 0) return memo[{ a, b }] = 1;
		return memo[{ a, b }] = cb(cb, a-1, b-1) + cb(cb, a-1, b); 
	};
	rep(i0, t0) {
		int n;
		string s;
		cin >> n >> s;
		mint res = 0;
		int bcnt = 0;
		rep(i, n) {
			if (s[i] == '1') ++bcnt;
			int slen = (i+1) * 2 - 1, tval = (slen + 1) / 2, sval = slen - tval;
			int tsum = (s[i] == '1') ? bcnt : (i+1 - bcnt);
			int sub = tval - tsum;
			if (sub < 0) continue;
			int tsub = sval - sub;
			res += cb(cb, sval, tsub);
		}
		cout << res.x << endl;
	}
	return 0;
}

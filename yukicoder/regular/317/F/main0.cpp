#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// バチャ本番,未完成

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
istream& operator>>(istream& is, mint& a) { return is >> a.x; }
ostream& operator<<(ostream& os, const mint& a) { return os << a.x; }

map<pair<int, ll>, mint> memo;

mint calc(int ai, ll ti) {
	if (memo.find({ai,ti}) != memo.end()) return memo[{ai,ti}];
	mint res = 0;
	if (ti == 0) {
		if (ai == 0) res = 1;
		else res = 0;
		return (memo[{ai,ti}] = res);
	}
	else if (ti == 1) {
		if (ai == 0) res = 1;
		else res = 0;
		res /= 3;
		return (memo[{ai,ti}] = res);
	}
	else {
		if (ti%2 == 0) {
			rep(i, 3) res += calc(i, ti/2) * calc((ai-i+3)%3, ti/2);
		}
		else {
			res += calc(ai, ti-1) / 3;
			rep(i, 3) if (i != ai) res += calc((ai-i+3)%3, ti-3) * calc(i, 1) / 9;
		}
		return (memo[{ai,ti}] = res);
	}
}

int main() {
	int t0;
	cin >> t0;
	rep(i0, t0) {
		ll n;
		cin >> n;
		memo = map<pair<int, ll>, mint>();
		mint res = calc(0, n);
		cout << res << endl;
	}
	return 0;
}

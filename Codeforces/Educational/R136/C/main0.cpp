// 本番AC

#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

const int INF = (int)(1e9);

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

struct combination {
	vector<mint> fact, ifact;
	combination(int n) : fact(n+1), ifact(n+1) {
		fact[0] = 1;
		for (int i=1; i<=n; ++i) fact[i] = fact[i-1] * i;
		ifact[n] = fact[n].inv();
		for (int i=n; i>=1; --i) ifact[i-1] = ifact[i] * i;
	}
	mint operator()(int n, int k) {
		if (k<0 || k>n) return 0;
		return (fact[n] * ifact[k] * ifact[n-k]);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	combination cb(61);
	vector<mint> memo(61);
	memo[2] = 0;
	for (int i=4; i<61; i+=2) {
		rep3r(j, 1, i-1) {
			int ai = i-j, bi = 1, si = i / 2;
			if (i-ai-bi < si-bi) break;
			memo[i] += cb(i-ai-bi, si-bi);
		}
	}
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<mint> res;
		mint aval = 0, bval = 0;
		for (int i=n; i>0; i-=2) {
			if ((n-i)/2%2 == 0) aval += cb(i-1, i/2);
			else aval += memo[i];
		}
		res.push_back(aval);
		for (int i=n; i>0; i-=2) {
			if ((n-i)/2%2 == 0) bval += memo[i];
			else bval += cb(i-1, i/2);
		}
		res.push_back(bval);
		res.push_back(1);
		rep(i, 3) cout << res[i].x << (i<2?' ':'\n');
	}
	return 0;
}

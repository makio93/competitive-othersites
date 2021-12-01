#include <bits/stdc++.h>
using namespace std;

using ll = long long;

#define rep(i, n) for (int i=0; i<(int)(n); ++(i))
#define rep3(i, m, n) for (int i=(m); (i)<(int)(n); ++(i))
#define repr(i, n) for (int i=(int)(n)-1; (i)>=0; --(i))
#define rep3r(i, m, n) for (int i=(int)(n)-1; (i)>=(int)(m); --(i))
#define all(x) (x).begin(), (x).end()

// 本番,未完成

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

struct BIT {
	int n;
	vector<mint> d;
	BIT(int n=0) : n(n), d(n+1) {}
	void add(int i, mint x=1) {
		for (i++; i<=n; i+=i&-i) {
			d[i] *= x;
		}
	}
	mint mul(int i) {
		mint x = 1;
		for (i++; i; i-=i&-i) {
			x *= d[i];
		}
		return x;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int t0;
	cin >> t0;
	rep(i0, t0) {
		int n;
		cin >> n;
		vector<int> a(n);
		rep(i, n) cin >> a[i];
		map<int, int> acnt;
		BIT mbt(n+1);
		mint res = 0;
		/* // ここで，総積版のBITを持ちながら計算しようとした
		rep(i, n) {
			if (a[i] == 1) res += mint(2).pow(acnt[a[i]]);
			else if (a[i] > 1) {
				res += mint(2).pow(acnt[a[i]])
			}
			res += mbt.mul()
		}
		*/
		cout << res << endl;
	}
	return 0;
}
